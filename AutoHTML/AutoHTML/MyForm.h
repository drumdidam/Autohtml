#pragma once
#include <msclr/marshal_cppstd.h>
#include <vector>
#include <atlstr.h>

namespace AutoHTML {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::TextBox^ TEditor;
	protected:


	private: System::Windows::Forms::TextBox^ TFilePath;


	private: System::Windows::Forms::Button^ BExec;
	private: System::Windows::Forms::Button^ BSelectFile;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TEditor = (gcnew System::Windows::Forms::TextBox());
			this->TFilePath = (gcnew System::Windows::Forms::TextBox());
			this->BExec = (gcnew System::Windows::Forms::Button());
			this->BSelectFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// TEditor
			// 
			this->TEditor->Location = System::Drawing::Point(235, 503);
			this->TEditor->Name = L"TEditor";
			this->TEditor->Size = System::Drawing::Size(1933, 26);
			this->TEditor->TabIndex = 0;
			// 
			// TFilePath
			// 
			this->TFilePath->Location = System::Drawing::Point(261, 199);
			this->TFilePath->Name = L"TFilePath";
			this->TFilePath->Size = System::Drawing::Size(1311, 26);
			this->TFilePath->TabIndex = 2;
			this->TFilePath->TextChanged += gcnew System::EventHandler(this, &MyForm::TFilePath_TextChanged);
			// 
			// BExec
			// 
			this->BExec->Location = System::Drawing::Point(1043, 347);
			this->BExec->Name = L"BExec";
			this->BExec->Size = System::Drawing::Size(367, 38);
			this->BExec->TabIndex = 3;
			this->BExec->Text = L"Run";
			this->BExec->UseVisualStyleBackColor = true;
			this->BExec->Click += gcnew System::EventHandler(this, &MyForm::BExec_Click);
			// 
			// BSelectFile
			// 
			this->BSelectFile->Location = System::Drawing::Point(1610, 182);
			this->BSelectFile->Name = L"BSelectFile";
			this->BSelectFile->Size = System::Drawing::Size(171, 61);
			this->BSelectFile->TabIndex = 4;
			this->BSelectFile->Text = L"ChooseFile";
			this->BSelectFile->UseVisualStyleBackColor = true;
			this->BSelectFile->Click += gcnew System::EventHandler(this, &MyForm::BSelectFile_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2339, 1309);
			this->Controls->Add(this->BSelectFile);
			this->Controls->Add(this->BExec);
			this->Controls->Add(this->TFilePath);
			this->Controls->Add(this->TEditor);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void BSelectFile_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		
		openFileDialog->Title = "Select a File";
		openFileDialog->Filter = "All Files (AllFiles (*.*)|*.*";
		openFileDialog->FilterIndex = 1;
		openFileDialog->RestoreDirectory = true;

		
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// Konvertiere den ausgewählten Dateipfad von System::String zu std::string
			std::string selectedFile = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);

			// Setze den ausgewählten Dateipfad in das Textfeld
			TFilePath->Text = gcnew String(selectedFile.c_str());
		}
		else
		{
			// Wenn keine Datei ausgewählt wurde, können Sie hier eine entsprechende Aktion ausführen
			MessageBox::Show("No file selected.");
		}
	}
private: System::Void TFilePath_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{

}
private: System::Void BExec_Click(System::Object^ sender, System::EventArgs^ e) 
{
	CString filepath = TFilePath->Text;

	
}
};
}
