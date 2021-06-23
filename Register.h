#pragma once
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <windows.h>
#include <stdio.h>

namespace HealthRecommendations {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace msclr::interop;
	using namespace std;

	/// <summary>
	/// Сводка для Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(String^ language)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			//инициализация верхней панели
			InitializeMenuStrip();

			//заполнение ролей
			rank_combobox->Items->Add("Пользователь");
			rank_combobox->Items->Add("Администратор");
			rank_combobox->SelectedItem = rank_combobox->Items[0];

			//изменение языка
			this->language = language;
			change_language();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::Label^ rank_label;
	private: System::Windows::Forms::Button^ register_button;

	protected:

	private:
		String^ reference;
		String^ reference_title;

		String^ register_error;
		String^ register_error_title;

		String^ login_exists_error;
		String^ login_exists_error_title;

		String^ register_msg;
		String^ register_msg_title;

		String^ language;



	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::TextBox^ login_textbox;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ComboBox^ rank_combobox;



		   /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->title_label = (gcnew System::Windows::Forms::Label());
			   this->rank_label = (gcnew System::Windows::Forms::Label());
			   this->register_button = (gcnew System::Windows::Forms::Button());
			   this->password_label = (gcnew System::Windows::Forms::Label());
			   this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			   this->login_label = (gcnew System::Windows::Forms::Label());
			   this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->rank_combobox = (gcnew System::Windows::Forms::ComboBox());
			   this->SuspendLayout();
			   // 
			   // title_label
			   // 
			   this->title_label->AutoSize = true;
			   this->title_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->title_label->Location = System::Drawing::Point(126, 85);
			   this->title_label->Name = L"title_label";
			   this->title_label->Size = System::Drawing::Size(170, 30);
			   this->title_label->TabIndex = 28;
			   this->title_label->Text = L"Регистрация";
			   // 
			   // rank_label
			   // 
			   this->rank_label->AutoSize = true;
			   this->rank_label->Location = System::Drawing::Point(10, 210);
			   this->rank_label->Name = L"rank_label";
			   this->rank_label->Size = System::Drawing::Size(40, 17);
			   this->rank_label->TabIndex = 49;
			   this->rank_label->Text = L"Роль";
			   // 
			   // register_button
			   // 
			   this->register_button->Location = System::Drawing::Point(116, 261);
			   this->register_button->Name = L"register_button";
			   this->register_button->Size = System::Drawing::Size(189, 44);
			   this->register_button->TabIndex = 50;
			   this->register_button->Text = L"Зарегистрировать";
			   this->register_button->UseVisualStyleBackColor = true;
			   this->register_button->Click += gcnew System::EventHandler(this, &Register::register_button_Click);
			   // 
			   // password_label
			   // 
			   this->password_label->AutoSize = true;
			   this->password_label->Location = System::Drawing::Point(10, 175);
			   this->password_label->Name = L"password_label";
			   this->password_label->Size = System::Drawing::Size(57, 17);
			   this->password_label->TabIndex = 53;
			   this->password_label->Text = L"Пароль";
			   // 
			   // password_textbox
			   // 
			   this->password_textbox->Location = System::Drawing::Point(180, 170);
			   this->password_textbox->Name = L"password_textbox";
			   this->password_textbox->Size = System::Drawing::Size(200, 22);
			   this->password_textbox->TabIndex = 52;
			   // 
			   // login_label
			   // 
			   this->login_label->AutoSize = true;
			   this->login_label->Location = System::Drawing::Point(12, 138);
			   this->login_label->Name = L"login_label";
			   this->login_label->Size = System::Drawing::Size(47, 17);
			   this->login_label->TabIndex = 55;
			   this->login_label->Text = L"Логин";
			   // 
			   // login_textbox
			   // 
			   this->login_textbox->Location = System::Drawing::Point(180, 133);
			   this->login_textbox->Name = L"login_textbox";
			   this->login_textbox->Size = System::Drawing::Size(200, 22);
			   this->login_textbox->TabIndex = 54;
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(421, 24);
			   this->menuStrip1->TabIndex = 56;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // rank_combobox
			   // 
			   this->rank_combobox->FormattingEnabled = true;
			   this->rank_combobox->Location = System::Drawing::Point(180, 210);
			   this->rank_combobox->Name = L"rank_combobox";
			   this->rank_combobox->Size = System::Drawing::Size(200, 24);
			   this->rank_combobox->TabIndex = 57;
			   // 
			   // Register
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(421, 317);
			   this->Controls->Add(this->rank_combobox);
			   this->Controls->Add(this->login_label);
			   this->Controls->Add(this->login_textbox);
			   this->Controls->Add(this->password_label);
			   this->Controls->Add(this->password_textbox);
			   this->Controls->Add(this->register_button);
			   this->Controls->Add(this->rank_label);
			   this->Controls->Add(this->title_label);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Register";
			   this->Text = L"AddEmployee";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: void InitializeMenuStrip() {
		ToolStripMenuItem^ interfaceItem = gcnew ToolStripMenuItem("Интерфейс");
		ToolStripMenuItem^ colorItem = gcnew ToolStripMenuItem("Цвет фона");
		colorItem->Click += gcnew System::EventHandler(this, &Register::colorItem_Click);
		interfaceItem->DropDownItems->Add(colorItem);

		ToolStripMenuItem^ languageItem = gcnew ToolStripMenuItem("Язык");
		auto languages = {
			 "Русский",
			 "Беларуская",
			 "English",
		};
		for (auto item : languages) {
			ToolStripMenuItem^ languageItemChild = gcnew ToolStripMenuItem(marshal_as<String^>(item));
			languageItemChild->Click += gcnew System::EventHandler(this, &Register::languageItem_Click);
			languageItem->DropDownItems->Add(languageItemChild);
		}

		ToolStripMenuItem^ aboutItem = gcnew ToolStripMenuItem("О программе");
		ToolStripMenuItem^ referenceItem = gcnew ToolStripMenuItem("Справка");
		referenceItem->Click += gcnew System::EventHandler(this, &Register::referenceItem_Click);
		aboutItem->DropDownItems->Add(referenceItem);


		menuStrip1->Items->Add(interfaceItem);
		menuStrip1->Items->Add(languageItem);
		menuStrip1->Items->Add(aboutItem);
	}

	private: bool login_exists(string name)
	{
		ifstream users_file("accounts\\Users.txt");
		string line;
		string login, password;
		bool login_line = true;
		while (getline(users_file, line))
		{
			if (login_line)
			{
				login_line = false;
				login = line;
				if (login == name)
					return true;
			}
			else
			{
				login_line = true;
			}
		}
		users_file.close();

		ifstream admins_file("accounts\\Admins.txt");
		login_line = true;
		while (getline(admins_file, line))
		{
			if (login_line)
			{
				login_line = false;
				login = line;
				if (login == name)
					return true;
			}
			else
			{
				login_line = true;
			}
		}

		return false;
	}

	private: System::Void register_button_Click(System::Object^ sender, System::EventArgs^ e) {
		string login = marshal_as<string>(login_textbox->Text->ToString());
		string password = marshal_as<string>(password_textbox->Text->ToString());
		bool admin = rank_combobox->SelectedIndex;

		if (
			login_textbox->Text->Replace(" ", "")->Length == 0
			)
		{
			MessageBox::Show(this, register_error, register_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (login_exists(login))
		{
			MessageBox::Show(this, login_exists_error, login_exists_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		string path;
		if (admin)
			path = "accounts\\Admins.txt";
		else
			path = "accounts\\Users.txt";

		ofstream file(path, ios::out | ios::app);
		file
			<< login << "\n"
			<< password << "\n"
			;
		file.close();

		MessageBox::Show(this, register_msg, register_msg_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}


	private: void change_language()
	{
		if (language == "Русский")
		{
			this->Text = "Регистрация";

			reference_title = "Справка";
			reference =
				"В данном окне можно произвести регистрацию пользователя.";

			menuStrip1->Items[0]->Text = "Интерфейс";
			menuStrip1->Items[1]->Text = "Язык";
			menuStrip1->Items[2]->Text = "О программе";
			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Цвет фона";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Справка";

			login_label->Text = "Логин";
			password_label->Text = "Пароль";

			register_button->Text = "Зарегистрировать";
			register_error = "Некоторые поля имели неверный формат";
			register_error_title = "Ошибка";

			register_msg = "Пользователь успешно добавлен";
			register_msg_title = "Успех";

			login_exists_error = "Логин уже существует!";
			login_exists_error_title = "Ошибка";

			rank_combobox->Items[0] = "Пользователь";
			rank_combobox->Items[1] = "Администратор";

			title_label->Text = "Регистрация";
		}
		else if (language == "Беларуская")
		{
			this->Text = "Регiстрацыя";

			reference_title = "Даведка";
			reference =
				"У дадзеным акне можна вырабіць рэгістрацыю карыстальніка.";

			menuStrip1->Items[0]->Text = "Iнтэрфейс";
			menuStrip1->Items[1]->Text = "Мова";
			menuStrip1->Items[2]->Text = "Аб праграме";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Колер фону";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Даведка";

			password_label->Text = "Пароль";

			register_error = "Некаторыя палі мелі няправільны фармат";
			register_error_title = "Памылка";

			register_msg = "Карыстальнiк паспяхова дададзены";
			register_msg_title = "Поспех";

			login_exists_error = "Лагін ўжо існуе!";
			login_exists_error_title = "Памылка";

			rank_combobox->Items[0] = "Карыстальнiк";
			rank_combobox->Items[1] = "Адмiн";

			title_label->Text = "Рэгістрацыя";

		}
		else if (language == "English")
		{
			this->Text = "Register";

			reference_title = "Reference";
			reference =
				"In this window you can register new user.";


			menuStrip1->Items[0]->Text = "Interface";
			menuStrip1->Items[1]->Text = "Language";
			menuStrip1->Items[2]->Text = "About program";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Background color";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Reference";

			login_label->Text = "Login";
			password_label->Text = "Password";

			register_error = "Some textbox had invalid format";
			register_error_title = "Error";

			register_msg = "User added successfully";
			register_msg_title = "Success";

			login_exists_error = "Login already exists!";
			login_exists_error_title = "Error";

			rank_combobox->Items[0] = "User";
			rank_combobox->Items[1] = "Admin";

			title_label->Text = "Register";

		}
	}

	private: void colorItem_Click(Object^ sender, EventArgs^ e)
	{
		ColorDialog^ colorDialog = gcnew ColorDialog(); //вызов окна, где можно выбрать цвет
		colorDialog->Color = this->BackColor; // выбираем текущий цвет по умолчанию

		if (colorDialog->ShowDialog().ToString() == "OK") //если пользоватеьл нажал ОК, то сменяем цвет фона на выбранный цвет
			this->BackColor = colorDialog->Color;
	}

	private: void languageItem_Click(Object^ sender, EventArgs^ e)
	{
		language = ((ToolStripMenuItem^)sender)->Text;
		change_language();
	}

	private: void referenceItem_Click(Object^ sender, EventArgs^ e)
	{
		MessageBox::Show(this, reference, reference_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	};
}
