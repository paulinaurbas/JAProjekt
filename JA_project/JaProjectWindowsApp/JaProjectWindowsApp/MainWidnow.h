#pragma once
#include <string>
#include "CPlusPlusDll.h"
namespace JaProjectWindowsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWidnow
	/// </summary>
	public ref class MainWidnow : public System::Windows::Forms::Form
	{
	public:
		MainWidnow(void)
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
		~MainWidnow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  NegativeLabelInfo;
	private: System::Windows::Forms::Button^  buttonLoad;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  AfterLabel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckBox^  checkBoxAsm;
	private: System::Windows::Forms::CheckBox^  CPlusPlusBox;


	private: System::Windows::Forms::Label^  label3;



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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->NegativeLabelInfo = (gcnew System::Windows::Forms::Label());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AfterLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxAsm = (gcnew System::Windows::Forms::CheckBox());
			this->CPlusPlusBox = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(41, 131);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(291, 240);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainWidnow::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(372, 131);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(291, 240);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MainWidnow::pictureBox2_Click);
			// 
			// NegativeLabelInfo
			// 
			this->NegativeLabelInfo->AutoSize = true;
			this->NegativeLabelInfo->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NegativeLabelInfo->Location = System::Drawing::Point(46, 50);
			this->NegativeLabelInfo->Name = L"NegativeLabelInfo";
			this->NegativeLabelInfo->Size = System::Drawing::Size(359, 31);
			this->NegativeLabelInfo->TabIndex = 2;
			this->NegativeLabelInfo->Text = L"Make negative from your picture";
			this->NegativeLabelInfo->Click += gcnew System::EventHandler(this, &MainWidnow::label1_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->Location = System::Drawing::Point(699, 208);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(83, 89);
			this->buttonLoad->TabIndex = 3;
			this->buttonLoad->Text = L"Load your picture!";
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &MainWidnow::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(37, 107);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 21);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Before";
			this->label1->Click += gcnew System::EventHandler(this, &MainWidnow::label1_Click_1);
			// 
			// AfterLabel
			// 
			this->AfterLabel->AutoSize = true;
			this->AfterLabel->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AfterLabel->Location = System::Drawing::Point(368, 107);
			this->AfterLabel->Name = L"AfterLabel";
			this->AfterLabel->Size = System::Drawing::Size(44, 21);
			this->AfterLabel->TabIndex = 5;
			this->AfterLabel->Text = L"After";
			this->AfterLabel->Click += gcnew System::EventHandler(this, &MainWidnow::AfterLabel_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(91, 424);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Speed Test";
			this->label2->Click += gcnew System::EventHandler(this, &MainWidnow::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(237, 428);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(438, 20);
			this->textBox1->TabIndex = 7;
			// 
			// checkBoxAsm
			// 
			this->checkBoxAsm->AutoSize = true;
			this->checkBoxAsm->Location = System::Drawing::Point(543, 64);
			this->checkBoxAsm->Name = L"checkBoxAsm";
			this->checkBoxAsm->Size = System::Drawing::Size(46, 17);
			this->checkBoxAsm->TabIndex = 8;
			this->checkBoxAsm->Text = L"Asm";
			this->checkBoxAsm->UseVisualStyleBackColor = true;
			this->checkBoxAsm->CheckedChanged += gcnew System::EventHandler(this, &MainWidnow::checkBoxAsm_CheckedChanged);
			// 
			// CPlusPlusBox
			// 
			this->CPlusPlusBox->AutoSize = true;
			this->CPlusPlusBox->Location = System::Drawing::Point(630, 64);
			this->CPlusPlusBox->Name = L"CPlusPlusBox";
			this->CPlusPlusBox->Size = System::Drawing::Size(45, 17);
			this->CPlusPlusBox->TabIndex = 9;
			this->CPlusPlusBox->Text = L"C++";
			this->CPlusPlusBox->UseVisualStyleBackColor = true;
			this->CPlusPlusBox->CheckedChanged += gcnew System::EventHandler(this, &MainWidnow::CPlusPlusBox_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(528, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(162, 23);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Choose asm or c++\?";
			this->label3->Click += gcnew System::EventHandler(this, &MainWidnow::label3_Click);
			// 
			// MainWidnow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 514);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->CPlusPlusBox);
			this->Controls->Add(this->checkBoxAsm);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->AfterLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonLoad);
			this->Controls->Add(this->NegativeLabelInfo);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainWidnow";
			this->Text = L"MainWidnow";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->Title = "Upload image";
		openFileDialog1->Filter = "Bitmap (*.bmp)|*.bmp";
		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		pictureBox2->Image = nullptr;
		MessageBox(Negative());
		
			
	}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CPlusPlusBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBoxAsm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void AfterLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
