#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

#include "Admin.h"
#include "User.h"
#include "Register.h"

namespace HealthRecommendations {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для Authentication
	/// </summary>
	public ref class Authentication : public System::Windows::Forms::Form
	{
	public:
		Authentication(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			InitializeMenuStrip();
			InitializeRankCombobox();

			change_language();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Authentication()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ComboBox^ rank_combobox;
	private: System::Windows::Forms::Button^ signin_button;
	private: System::Windows::Forms::Label^ password_label;


	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Label^ signin_label;
	private: System::Windows::Forms::TextBox^ login_textbox;


	private:
		String^ reference;
		String^ reference_title;
		String^ signin_error;
		String^ signin_error_title;
		String^ language = "Русский";
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::Button^ register_button;

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
			this->rank_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->signin_button = (gcnew System::Windows::Forms::Button());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->signin_label = (gcnew System::Windows::Forms::Label());
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rank_combobox
			// 
			this->rank_combobox->FormattingEnabled = true;
			this->rank_combobox->Location = System::Drawing::Point(127, 118);
			this->rank_combobox->Name = L"rank_combobox";
			this->rank_combobox->Size = System::Drawing::Size(200, 24);
			this->rank_combobox->TabIndex = 34;
			// 
			// signin_button
			// 
			this->signin_button->Location = System::Drawing::Point(127, 258);
			this->signin_button->Name = L"signin_button";
			this->signin_button->Size = System::Drawing::Size(189, 44);
			this->signin_button->TabIndex = 33;
			this->signin_button->Text = L"Войти";
			this->signin_button->UseVisualStyleBackColor = true;
			this->signin_button->Click += gcnew System::EventHandler(this, &Authentication::signin_button_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(47, 203);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(57, 17);
			this->password_label->TabIndex = 32;
			this->password_label->Text = L"Пароль";
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->Location = System::Drawing::Point(48, 161);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(47, 17);
			this->login_label->TabIndex = 29;
			this->login_label->Text = L"Логин";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(127, 203);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '*';
			this->password_textbox->Size = System::Drawing::Size(200, 22);
			this->password_textbox->TabIndex = 28;
			// 
			// signin_label
			// 
			this->signin_label->AutoSize = true;
			this->signin_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signin_label->Location = System::Drawing::Point(151, 75);
			this->signin_label->Name = L"signin_label";
			this->signin_label->Size = System::Drawing::Size(136, 30);
			this->signin_label->TabIndex = 27;
			this->signin_label->Text = L"Войти как";
			// 
			// login_textbox
			// 
			this->login_textbox->Location = System::Drawing::Point(127, 161);
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(200, 22);
			this->login_textbox->TabIndex = 26;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(418, 24);
			this->menuStrip1->TabIndex = 38;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// register_button
			// 
			this->register_button->Location = System::Drawing::Point(12, 39);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(166, 33);
			this->register_button->TabIndex = 39;
			this->register_button->Text = L"Регистрация";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &Authentication::register_button_Click);
			// 
			// Authentication
			// 
			this->AcceptButton = this->signin_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 321);
			this->Controls->Add(this->register_button);
			this->Controls->Add(this->rank_combobox);
			this->Controls->Add(this->signin_button);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->login_label);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->signin_label);
			this->Controls->Add(this->login_textbox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Authentication";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Authentication";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: void change_language()
	{
		if (language == "Русский")
		{
			this->Text = "Авторизация";

			menuStrip1->Items[0]->Text = "Интерфейс";
			menuStrip1->Items[1]->Text = "Язык";
			menuStrip1->Items[2]->Text = "О программе";
			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Цвет фона";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Справка";


			reference_title = "Справка";
			reference =
				"В данном окне происходит авторизация пользователя.\n" +
				"В систему можно войти как пользователь, либо как администратор";

			signin_label->Text = "Войти как";
			signin_button->Text = "Вход";
			login_label->Text = "Логин";
			password_label->Text = "Пароль";

			signin_error = "Неправильный логин либо пароль!";
			signin_error_title = "Ошибка входа";

			rank_combobox->Items[0] = "Пользователь";
			rank_combobox->Items[1] = "Администратор";
		}
		else if (language == "Беларуская")
		{
			this->Text = "Аўтарызацыя";

			menuStrip1->Items[0]->Text = "Iнтэрфейс";
			menuStrip1->Items[1]->Text = "Мова";
			menuStrip1->Items[2]->Text = "Аб праграме";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Колер фону";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Даведка";

			reference_title = "Даведка";
			reference =
				"У дадзеным акне адбываецца аўтарызацыя карыстальніка.\n" +
				"У сістэму можна ўвайсці як супрацоўнік арганізацыі, альбо як адміністратар";

			signin_label->Text = "Увайсці як";
			signin_button->Text = "Уваход";
			login_label->Text = "Лагін";
			password_label->Text = "Пароль";

			signin_error = "Няправільны лагін альбо пароль!";
			signin_error_title = "Памылка ўваходу";

			rank_combobox->Items[0] = "Карыстальнік";
			rank_combobox->Items[1] = "Адміністратар";
		}
		else if (language == "English")
		{
			this->Text = "Authorization";

			menuStrip1->Items[0]->Text = "Interface";
			menuStrip1->Items[1]->Text = "Language";
			menuStrip1->Items[2]->Text = "About program";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Background color";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Reference";

			reference_title = "Reference";
			reference =
				"In this window, the user is authorized.\n" +
				"You can enter the system as an employee of the organization, or as an administrator";

			signin_label->Text = "Signin as";
			signin_button->Text = "Enter";
			login_label->Text = "Login";
			password_label->Text = "Password";

			reference_title = "Reference";

			signin_error = "Wrong login or password!";
			signin_error_title = "Sign in error";

			rank_combobox->Items[0] = "User";
			rank_combobox->Items[1] = "Admin";
		}
	}

	private: System::Void color_button_Click(System::Object^ sender, System::EventArgs^ e) {
		ColorDialog^ colorDialog = gcnew ColorDialog(); //вызов окна, где можно выбрать цвет
		colorDialog->Color = this->BackColor; // выбираем текущий цвет по умолчанию

		if (colorDialog->ShowDialog().ToString() == "OK") //если пользоватеьл нажал ОК, то сменяем цвет фона на выбранный цвет
			this->BackColor = colorDialog->Color;
	}
	private: System::Void reference_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(this, reference, reference_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: bool validate(std::string type)
	{
		std::ifstream users_file("accounts\\" + type + ".txt");
		if (users_file.is_open() == false)
		{
			return false;
		}
		std::string line;
		std::string login, password;
		bool login_line = true;
		while (std::getline(users_file, line))
		{
			if (login_line)
			{
				login_line = false;
				login = line;
			}
			else
			{
				login_line = true;
				password = line;
				if (marshal_as<String^>(login) == login_textbox->Text
					&& marshal_as<String^>(password) == password_textbox->Text)
				{
					return true;
				}
			}
		}
		return false;
	}

	private: System::Void signin_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ form;
		bool success = false;

		if (rank_combobox->SelectedIndex == 0)
		{
			success = validate("Users");
			if (success)
				form = gcnew User(login_textbox->Text, language);
		}
		else if (rank_combobox->SelectedIndex == 1)
		{
			success = validate("Admins");
			if (success)
				form = gcnew Admin(language);
		}

		if (!success)
			MessageBox::Show(this, signin_error, signin_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			form->Show();
	}
	
		   private: void InitializeRankCombobox() {
			   rank_combobox->Items->Add("Пользователь");
			   rank_combobox->Items->Add("Администратор");
			   rank_combobox->SelectedItem = rank_combobox->Items[0];
		   }

		   private: void InitializeMenuStrip() {
			   ToolStripMenuItem^ interfaceItem = gcnew ToolStripMenuItem("Интерфейс");
			   ToolStripMenuItem^ colorItem = gcnew ToolStripMenuItem("Цвет фона");
			   colorItem->Click += gcnew System::EventHandler(this, &Authentication::colorItem_Click);
			   interfaceItem->DropDownItems->Add(colorItem);

			   ToolStripMenuItem^ languageItem = gcnew ToolStripMenuItem("Язык");
			   auto languages = {
				    "Русский",
				    "Беларуская",
				    "English",
			   };
			   for (auto item : languages) {
				   ToolStripMenuItem^ languageItemChild = gcnew ToolStripMenuItem(marshal_as<String^>(item));
				   languageItemChild->Click += gcnew System::EventHandler(this, &Authentication::languageItem_Click);
				   languageItem->DropDownItems->Add(languageItemChild);
			   }

			   ToolStripMenuItem^ aboutItem = gcnew ToolStripMenuItem("О программе");
			   ToolStripMenuItem^ referenceItem = gcnew ToolStripMenuItem("Справка");
			   referenceItem->Click += gcnew System::EventHandler(this, &Authentication::referenceItem_Click);
			   aboutItem->DropDownItems->Add(referenceItem);


			   menuStrip1->Items->Add(interfaceItem);
			   menuStrip1->Items->Add(languageItem);
			   menuStrip1->Items->Add(aboutItem);
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

	private: System::Void register_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Register^ reg = gcnew Register(language);
		reg->Show();
	}
};
}

