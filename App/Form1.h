#pragma once

#include <stdio.h> 
#include <string.h>


int  ReadIndex;
int  ReadCount;

//SerialPort^ serialPort485 = gcnew SerialPort();





namespace App {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
         
		//array<unsigned char>^ReceiveBuffer2 = gcnew array<unsigned char>(0xFF);
		Form1(void)
		{
			InitializeComponent();

           // V3_Function();


			//
			//TODO: 在此处添加构造函数代码
			//
		}
	    


	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^      button1;
	private: System::Windows::Forms::Label^       label1;
	private: System::IO::Ports::SerialPort^       serialPort1;
	private: System::Windows::Forms::ComboBox^    comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;

	protected: 
       //TODO 
	private:


		//Thread^ ReceiveThread = gcnew Thread( gcnew ThreadStart( &ThreadExample::ThreadProc);

		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(169, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"打开串口";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(289, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Status:";
			// 
			// serialPort1
			// 
			this->serialPort1->Parity = System::IO::Ports::Parity::Even;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(28, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"SN Input:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(91, 68);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 21);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(91, 113);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"写入";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 396);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"V3 APP";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {				
				 
				 if(this->serialPort1 ->IsOpen == false)
				 {
					 this->serialPort1->PortName = comboBox1->Text;
					 this->serialPort1->BaudRate = 9600;   
					 this->serialPort1->StopBits = System::IO::Ports::StopBits::One;
					 this->serialPort1->Parity = System::IO::Ports::Parity::Even;
					 this->serialPort1->DataBits = 8;
					 this->serialPort1->ReadTimeout = 500;
					 this->serialPort1->WriteTimeout = 500;

					 try
					 {
						 this->serialPort1->Open();	
						 this->button1->Text = "关闭串口";
						 this->label1->Text = "Success To Init COM Port";
					 }
					 catch (TimeoutException ^)
					 {
						 this->label1->Text = "初始化超时";
					 }
					 catch (UnauthorizedAccessException ^)
					 {
						 this->label1->Text = "该串口被占用";
					 }
					 


				 }
				 else if(this->serialPort1 ->IsOpen == true)
				 {	
					 this->serialPort1->Close();	
					 this->button1->Text = "打开串口";
				     this->label1->Text = "Success To Close COM Port";
				   
				 }

			 }


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
                this->label1->Text = "Status";
				for each (String^ s in SerialPort::GetPortNames())
				{
					comboBox1->Items->Add(s);
				}
			 }

    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				  
				  unsigned char i =0;
				  char Buffer[0xFF] = {0};
				  String^InputData = this->textBox1->Text;


				  
				  if(sizeof(InputData) < 16)
				  {
		
				  				
				  }
				  else
				  {
					  for(i =0;i<16;i++)
					  {
						Buffer[i] = InputData[i];
					  }				  				 				 
				  }


				  
				  

		 }
};
}



