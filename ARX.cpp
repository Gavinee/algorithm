    #include<aced.h>				//ARX应用程序定义和访问AutoCAD指定服务所需要的头文件
    #include<rxregsvc.h>			//acrxXXX工具函数所需的头文件

    void initApp();					//在加载时所调用
    void unloadApp();			    //在程序被卸载时所调用

    void HelloWorld();

    void initApp()
    {
      acedRegCmds->addCommand(
        "Hello1",
        "Hello",			//输入这两个命令名称均可以在AutoCAD中运行程序
        "Hello",			
        ACRX_CMD_MODAL,	    //模态命令	
        HelloWorld
        );
    }

    virtual Acad::ErrorStatus addCommand(
      const char* cmdGroupName,			//指定命令组名称
      const char* cmdGlobalName,		    //命令的国际名称
      const char* cmdLocalName,			//命令的本国名称
      Adesk::Int32 commandFlags,			//命令的类型
      AcRxFunctionPtr FunctionAddr,	    //指向实现函数的指针
      AcEdUIContext* UIContext = NULL,
      int fcode = -1,
      HINSTANCE hResourceHandle = NULL,
      AcEdCommand** cmdPtrRet = NULL) = 0;

    commandFlags是用来说明命令类型的   (1)模态命令  模态命令在执行过程中无法运行其他的模态命令，但是可以运行透明命令
                       (2)透明命令	 

void unloadApp()
{
	//删除命令组
	acedRegCmds->removeGroup("Hello1");
}

void HelloWorld()
{
	acutPrintf("\nHell,World!");	 //相当于C语言中的printf函数
}

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg,void* pkt)
{
	switch(msg)
	{
	case AcRx::kInitAppMsg:			//应用程序加载时发生
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:		//应用程序卸载后发生
		unloadApp();
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


