// App.cpp: 主项目文件。

#include "stdafx.h"
#include "Form1.h"

using namespace App;
using namespace System::Threading;


void V3_Function(void)
{				 ReadIndex++; 
	try
	{
		//if(_serialPort->BytesToRead > 1)
		//{
	//		_serialPort->Read(ReceiveBuffer,0,_serialPort->BytesToRead);						  
	//	}
	}
	catch (TimeoutException ^) { }

}

public ref class ThreadExample
{
public:

	// The ThreadProc method is called when the thread starts.
	// It loops ten times, writing to the console and yielding 
	// the rest of its time slice each time, and then ends.
	static void ThreadProc()
	{
     // V3_Function();
	}

};

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Thread^ ReceiveThread = gcnew Thread( gcnew ThreadStart( &ThreadExample::ThreadProc));
	ReceiveThread->Start();

	Application::Run(gcnew Form1());




	return 0;
}
