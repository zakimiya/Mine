#pragma once
#include "stdio.h"
#include "stdlib.h"
#include <string>  

#include "part.h"
#include "gallary.h"
#include "folder.h"
#include "rename_p.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;


	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox16;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(40, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(176, 19);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(452, 274);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"実行！";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(40, 108);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(176, 19);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(279, 47);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(299, 19);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 172);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(64, 19);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 217);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(90, 19);
			this->textBox5->TabIndex = 5;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(117, 172);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(64, 19);
			this->textBox6->TabIndex = 6;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(117, 217);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(99, 19);
			this->textBox7->TabIndex = 7;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(358, 217);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(105, 19);
			this->textBox8->TabIndex = 11;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(358, 172);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(64, 19);
			this->textBox9->TabIndex = 10;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(234, 217);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(102, 19);
			this->textBox10->TabIndex = 9;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(234, 172);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(64, 19);
			this->textBox11->TabIndex = 8;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(493, 217);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(103, 19);
			this->textBox14->TabIndex = 13;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(493, 172);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(64, 19);
			this->textBox15->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 12);
			this->label1->TabIndex = 16;
			this->label1->Text = L"ページ名";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 12);
			this->label2->TabIndex = 17;
			this->label2->Text = L"フォルダ名";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(279, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 12);
			this->label3->TabIndex = 18;
			this->label3->Text = L"URL";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(279, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 12);
			this->label4->TabIndex = 19;
			this->label4->Text = L"ページ数";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(279, 107);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(68, 19);
			this->textBox16->TabIndex = 20;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(608, 329);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void MarshalString(String ^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			char pagename_c[20] = "";		//ページの名前
			std::string pagename_s;

			char foldername_c[20] = "";	//フォルダの名前(年度含む)
			std::string foldername_s;

			int page = 0;				//ページの枚数
			int picture[6] = { 0,0,0,0,0,0 };			//1ページあたりの写真の枚数

			char comment_1c[256] = "", comment_2c[256] = "", comment_3c[256] = "", 
				 comment_4c[256] = "", comment_5c[256] = "";
			std::string comment_1s, comment_2s, comment_3s, comment_4s, comment_5s;
			//ページごとに表示するコメント

			char url_c[256] = ""; //トップページのURL
			std::string url_s;

			MarshalString(textBox1->Text, pagename_s);
			pagename_s.copy(pagename_c, pagename_s.size());

			MarshalString(textBox2->Text, foldername_s);
			foldername_s.copy(foldername_c, foldername_s.size());

			page = Convert::ToInt32(textBox16->Text);

			MarshalString(textBox3->Text, url_s);
			url_s.copy(url_c, url_s.size());

			picture[1] = Convert::ToInt32(textBox4->Text);
			MarshalString(textBox5->Text, comment_1s);
			comment_1s.copy(comment_1c, comment_1s.size());

			if (page > 2) {
				picture[2] = Convert::ToInt32(textBox6->Text);
				MarshalString(textBox7->Text, comment_2s);
				comment_2s.copy(comment_2c, comment_2s.size());
			}
			if (page > 3) {
				picture[3] = Convert::ToInt32(textBox11->Text);
				MarshalString(textBox10->Text, comment_3s);
				comment_3s.copy(comment_3c, comment_3s.size());
			}
			if (page > 4){
				picture[4] = Convert::ToInt32(textBox9->Text);
				MarshalString(textBox8->Text, comment_4s);
				comment_4s.copy(comment_4c, comment_4s.size());
			}
			if (page > 5) {
				picture[5] = Convert::ToInt32(textBox15->Text);
				MarshalString(textBox14->Text, comment_5s);
				comment_5s.copy(comment_5c, comment_5s.size());
			}

			folder_make(foldername_c, page);
			part_make(foldername_c, pagename_c, page, picture);
			gallary_make(foldername_c, pagename_c, page, picture, comment_1c, comment_2c, comment_3c, comment_4c, comment_5c, url_c);

			rename_picture(foldername_c, picture);

			this->Close();
		}
	};
}
