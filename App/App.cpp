// App.cpp: ����Ŀ�ļ���

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
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Thread^ ReceiveThread = gcnew Thread( gcnew ThreadStart( &ThreadExample::ThreadProc));
	ReceiveThread->Start();

	Application::Run(gcnew Form1());




	return 0;
}
