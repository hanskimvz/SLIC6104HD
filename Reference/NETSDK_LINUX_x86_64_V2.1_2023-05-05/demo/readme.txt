1、为方便gdb调试，lib和demo makefile都加上了-g。发布时请strip
2、由于我司对各DSP方案定义的数据结构有区别，NETSDK中为了兼容所有DSP方案的IPCAMERA，将各DSP适配的结构体成员都打开了。应用的MAKEFILE中需要设置 -DLINUX -DNETSDK，否则会造成结构体大小不一致而出现段错误。
3、不建议使用者直接使用NETSDK中的收流API进行收流。libNetSDK_no_live555.a/so为不带RTSP收流的，使用该lib时，请勿调用预览相关的API。
4、音频对讲在LINUX SDK中暂未处理。
