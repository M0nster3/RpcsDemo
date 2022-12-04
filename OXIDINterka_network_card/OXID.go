package main

import (
	"bytes"
	"encoding/hex"
	"flag"
	"fmt"
	"net"
	"strconv"
	"strings"
	"sync"
	"time"
)
var (
	check string
	Allip []string
	bufferV1, _ = hex.DecodeString("05000b03100000004800000001000000b810b810000000000100000000000100c4fefc9960521b10bbcb00aa0021347a00000000045d888aeb1cc9119fe808002b10486002000000")
	bufferV2, _ = hex.DecodeString("050000031000000018000000010000000000000000000500")
	bufferV3, _ = hex.DecodeString("0900ffff")
	seconds =1
	//write = make(chan string,500)
	//read  = make(chan bool ,1)

)

func init() {

	flag.StringVar(&check,"i", "", "输入地址段")
}

func parse(s string) []string{
	fen := strings.Split(s,"-")
	fen1 := strings.Split(fen[0],".")
	fen2 := strings.Split(fen[1],".")
	starts ,ends:= [4]int{},[4]int{}
	for i :=0;i<len(fen1);i++{
		start,_ := strconv.Atoi(fen1[i])
		end,_:= strconv.Atoi(fen2[i])
		starts[i],ends[i] = start,end
	}
	startNum := starts[0]<<24 | starts[1]<<16 | starts[2]<<8 | starts[3]
	endNum := ends[0]<<24 | ends[1]<<16 | ends[2]<<8 | ends[3]
	for num := startNum;num<=endNum;num++{
		ip := strconv.Itoa((num>>24)&0xff) + "." + strconv.Itoa((num>>16)&0xff) + "." + strconv.Itoa((num>>8)&0xff) + "." + strconv.Itoa((num)&0xff)
		Allip = append(Allip, ip)
	}
	return Allip

}
func parsenet(hosts string) {
	var wg sync.WaitGroup
	hosts=hosts+":"+strconv.Itoa(135)
	conn, err := net.DialTimeout("tcp", hosts, time.Duration(seconds)*time.Second)
	if err != nil {

	} else {
		//fmt.Println(111)
		_, _ = conn.Write(bufferV1)
		reply := make([]byte, 4096)
		_, _ = conn.Read(reply)
		_, _ = conn.Write(bufferV2)
		_, _ = conn.Read(reply)
		reply=reply[42:]
		for f:=0;f<len(reply);f++{
			if bytes.Equal(reply[f:f+4],bufferV3){
				encode:= hex.EncodeToString(reply[0:f])
				sql:=strings.Split(encode,"0700")
				wg.Add(1)
				for i:=0;i<len(sql);i++{
					rep:= strings.Replace(sql[i],"00","",-1)
					dec,_:=hex.DecodeString(rep)
					//te := "[+] "+string(dec)+"\n"
					fmt.Print("[+] ",string(dec),"\n" )
					//write <-te
				}
				fmt.Print("\n" )
				wg.Done()
				break
			}
		}
	}
}
//func reads(){
//	time.Sleep(time.Second *1)
//	for {
//		v,ok :=<-write
//		if !ok{
//			break
//		}
//		fmt.Println(v)
//	}
//
//}
//返回用-表示的ip段,192.168.1.0-192.168.255.255
func IPS(c *net.IPNet) string {
	start := c.IP.String()
	mask := c.Mask
	bcst := make(net.IP, len(c.IP))
	copy(bcst, c.IP)
	for i := 0; i < len(mask); i++ {
		ipIdx := len(bcst) - i - 1
		bcst[ipIdx] = c.IP[ipIdx] |^mask[len(mask)-i-1]
	}
	end := bcst.String()
	return fmt.Sprintf("%s-%s", start, end)
}

func main(){
	var wg sync.WaitGroup
	flag.Parse()
	//f := strings.Split(check, "/")
	//fmt.Print(f[1],"\n")
	_, ipNet, _ := net.ParseCIDR(check)
	hosts:=parse(IPS(ipNet) )
	for i:=0;i<len(hosts);i++{
		go parsenet(hosts[i])
	}
	wg.Wait()
	time.Sleep(time.Second*3)
	//reads()


}