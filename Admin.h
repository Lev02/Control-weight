#pragma once

#include "Authentication.h"

#include <initializer_list>
#include <msclr\marshal_cppstd.h>
#include <filesystem>


namespace HealthRecommendations {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	/// <summary>
	/// Сводка для Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(String^ language)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			InitializeMenuStrip();
			InitializeProducts();

			this->language = language;
			change_language();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Admin()
		{
			SaveProducts();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:

	private:
		String^ reference;
		String^ reference_title;
		String^ language;
		int current_product_textbox = 1;
		int current_product_textbox_x = 12;
		int current_product_textbox_y = 125;
		int margin_between_products = 25;
		int margin_between_textboxes = 70;
		int product_textbox_width = 65;
		int product_textbox_height = 22;

		int current_selected_element;
	private: System::Windows::Forms::Label^ products_list_label;





	private: System::Windows::Forms::Button^ add_product_button;

	private: System::Windows::Forms::Label^ name_label;
	private: System::Windows::Forms::Label^ protein_label;
	private: System::Windows::Forms::Label^ fat_label;
	private: System::Windows::Forms::Label^ carbohydrates_label;
	private: System::Windows::Forms::Label^ calories_label;




		   /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->products_list_label = (gcnew System::Windows::Forms::Label());
			this->add_product_button = (gcnew System::Windows::Forms::Button());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->protein_label = (gcnew System::Windows::Forms::Label());
			this->fat_label = (gcnew System::Windows::Forms::Label());
			this->carbohydrates_label = (gcnew System::Windows::Forms::Label());
			this->calories_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(509, 30);
			this->menuStrip1->TabIndex = 39;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// products_list_label
			// 
			this->products_list_label->AutoSize = true;
			this->products_list_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->products_list_label->Location = System::Drawing::Point(12, 43);
			this->products_list_label->Name = L"products_list_label";
			this->products_list_label->Size = System::Drawing::Size(277, 25);
			this->products_list_label->TabIndex = 40;
			this->products_list_label->Text = L"Список продуктов в рационе";
			// 
			// add_product_button
			// 
			this->add_product_button->Location = System::Drawing::Point(312, 46);
			this->add_product_button->Name = L"add_product_button";
			this->add_product_button->Size = System::Drawing::Size(25, 25);
			this->add_product_button->TabIndex = 42;
			this->add_product_button->Text = L"+";
			this->add_product_button->UseVisualStyleBackColor = true;
			this->add_product_button->Click += gcnew System::EventHandler(this, &Admin::add_product_button_Click);
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Location = System::Drawing::Point(16, 90);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(72, 17);
			this->name_label->TabIndex = 43;
			this->name_label->Text = L"Название";
			// 
			// protein_label
			// 
			this->protein_label->AutoSize = true;
			this->protein_label->Location = System::Drawing::Point(109, 90);
			this->protein_label->Name = L"protein_label";
			this->protein_label->Size = System::Drawing::Size(55, 17);
			this->protein_label->TabIndex = 44;
			this->protein_label->Text = L"Белков";
			// 
			// fat_label
			// 
			this->fat_label->AutoSize = true;
			this->fat_label->Location = System::Drawing::Point(209, 90);
			this->fat_label->Name = L"fat_label";
			this->fat_label->Size = System::Drawing::Size(52, 17);
			this->fat_label->TabIndex = 45;
			this->fat_label->Text = L"Жиров";
			// 
			// carbohydrates_label
			// 
			this->carbohydrates_label->AutoSize = true;
			this->carbohydrates_label->Location = System::Drawing::Point(309, 90);
			this->carbohydrates_label->Name = L"carbohydrates_label";
			this->carbohydrates_label->Size = System::Drawing::Size(76, 17);
			this->carbohydrates_label->TabIndex = 46;
			this->carbohydrates_label->Text = L"Углеводов";
			// 
			// calories_label
			// 
			this->calories_label->AutoSize = true;
			this->calories_label->Location = System::Drawing::Point(409, 90);
			this->calories_label->Name = L"calories_label";
			this->calories_label->Size = System::Drawing::Size(65, 17);
			this->calories_label->TabIndex = 48;
			this->calories_label->Text = L"Калорий";
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 213);
			this->Controls->Add(this->calories_label);
			this->Controls->Add(this->carbohydrates_label);
			this->Controls->Add(this->fat_label);
			this->Controls->Add(this->protein_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->add_product_button);
			this->Controls->Add(this->products_list_label);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	

	private: void InitializeMenuStrip() {
		ToolStripMenuItem^ interfaceItem = gcnew ToolStripMenuItem("Интерфейс");
		ToolStripMenuItem^ colorItem = gcnew ToolStripMenuItem("Цвет фона");
		colorItem->Click += gcnew System::EventHandler(this, &Admin::colorItem_Click);
		interfaceItem->DropDownItems->Add(colorItem);

		ToolStripMenuItem^ languageItem = gcnew ToolStripMenuItem("Язык");
		auto languages = {
			 "Русский",
			 "Беларуская",
			 "English",
		};
		for (auto item : languages) {
			ToolStripMenuItem^ languageItemChild = gcnew ToolStripMenuItem(marshal_as<String^>(item));
			languageItemChild->Click += gcnew System::EventHandler(this, &Admin::languageItem_Click);
			languageItem->DropDownItems->Add(languageItemChild);
		}

		ToolStripMenuItem^ aboutItem = gcnew ToolStripMenuItem("О программе");
		ToolStripMenuItem^ referenceItem = gcnew ToolStripMenuItem("Справка");
		referenceItem->Click += gcnew System::EventHandler(this, &Admin::referenceItem_Click);
		aboutItem->DropDownItems->Add(referenceItem);


		menuStrip1->Items->Add(interfaceItem);
		menuStrip1->Items->Add(languageItem);
		menuStrip1->Items->Add(aboutItem);
	}

	private: void SaveProducts()
	{
		//поиск индекса первого нужного textbox'a
		int start;
		for (size_t i = 0; i < this->Controls->Count; i++) {
			if (this->Controls[i]->Name == "product_textbox1") {
				start = i;
				break;
			}
		}

		int j = start;

		while (j + 5 <= start + current_product_textbox) {
			if (this->Controls[j]->Text->Replace(" ", "") == "") {
				j += 5;
				continue;
			}

			std::string path = "products\\" + marshal_as<std::string>(this->Controls[j]->Text) + ".txt";
			std::ofstream product_file(path);
			for (size_t i = 0; i < 5; i++) {
				product_file << marshal_as<std::string>(this->Controls[j]->Text) << "\n";
				j++;
			}
			product_file.close();
		}
	}

	private: void InitializeProducts()
	{
		std::vector<std::vector<std::string>> products_info;

		std::string products_folder_path = "products";

		//проход по каждому файлу в папке products_folder_path
		for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(products_folder_path)) {
			std::ifstream product(dirEntry.path());
			std::string line;
			std::vector<std::string> product_info;
			while (getline(product, line)) {
				product_info.emplace_back(line);
			}
			products_info.push_back(product_info);
		}
		
		for (auto product_info : products_info) {
			create_product(product_info);
		}
	}

	private: void create_product(std::vector<std::string> product_info) {
		for (auto info : product_info) {
			create_product_textbox(marshal_as<String^>(info));
			current_product_textbox_x += margin_between_textboxes;
		}
		current_product_textbox_y += margin_between_products;
		current_product_textbox_x -= margin_between_textboxes * product_info.size();
		
		this->Size = System::Drawing::Size(this->Size.Width, this->Size.Height + margin_between_products);
	}

	private: void create_product_textbox(String^ text) {
		TextBox^ product_textbox = (gcnew TextBox());
		product_textbox->Location = System::Drawing::Point(current_product_textbox_x, current_product_textbox_y);
		product_textbox->Size = System::Drawing::Size(product_textbox_width, product_textbox_height);
		product_textbox->Name = "product_textbox" + current_product_textbox.ToString();
		product_textbox->Text = text;
		product_textbox->TextAlign = HorizontalAlignment::Center;
		if (current_product_textbox % 5 != 1) {
			product_textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Admin::number_textbox_KeyPress);
		}		
		product_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Admin::OnKeyDown);
		
		this->Controls->Add(product_textbox);

		current_product_textbox++;
	}

	private: void number_textbox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		try
		{
			TextBox^ textBox = (TextBox^)sender;
			if (!iscntrl(e->KeyChar) && !isdigit(e->KeyChar) &&
				(e->KeyChar != '.'))
				e->Handled = true;
			// разрешить ввод только одной точки
			if ((e->KeyChar == '.') && textBox->Text->IndexOf('.') > -1)
				e->Handled = true;
		}
		catch (...) {}
	}

	//метод для передвижения с помощью стрелок вправо, влево
	private: void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		bool arrow_pressed = false;
		TextBox^ textBox = (TextBox^)sender;
		std::string num_str = "";
		if (isdigit(textBox->Name[textBox->Name->Length - 2])) {
			num_str += textBox->Name[textBox->Name->Length - 2];
		}
		if (isdigit(textBox->Name[textBox->Name->Length - 1])) {
			num_str += textBox->Name[textBox->Name->Length - 1];
		}

		current_selected_element = std::stoi(num_str);

		if (e->KeyCode == Keys::Left) {
			if (current_selected_element - 1 > 0) {
				current_selected_element--;
				arrow_pressed = true;
			}
		}
		else if (e->KeyCode == Keys::Right) {
			if (current_selected_element + 1 <= current_product_textbox) {
				current_selected_element++;
				arrow_pressed = true;
			}
		}

		if (arrow_pressed) {
			for (size_t i = 0; i < this->Controls->Count; i++)
			{
				if (this->Controls[i]->Name == "product_textbox" + current_selected_element.ToString()) {
					this->Controls[i]->Select();
					break;
				}
			}
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

	private: void change_language()
	{
		if (language == "Русский")
		{
			this->Text = "Администратор";

			menuStrip1->Items[0]->Text = "Интерфейс";
			menuStrip1->Items[1]->Text = "Язык";
			menuStrip1->Items[2]->Text = "О программе";
			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Цвет фона";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Справка";

			products_list_label->Text = "Список продуктов в рационе";
			name_label->Text = "Название";
			carbohydrates_label->Text = "Углеводы";
			protein_label->Text = "Белки";
			fat_label->Text = "Жиры";
			calories_label->Text = "Калорий";
			


			reference_title = "Справка";
			reference =
				"В данном окне происходит добавление продуктов.\n" +
				"в рацион пользователя.";
		}
		else if (language == "Беларуская")
		{
			this->Text = "Адміністратар";

			menuStrip1->Items[0]->Text = "Iнтэрфейс";
			menuStrip1->Items[1]->Text = "Мова";
			menuStrip1->Items[2]->Text = "Аб праграме";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Колер фону";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Даведка";

			products_list_label->Text = "Спіс прадуктаў у рацыёне";
			name_label->Text = "Назва";
			carbohydrates_label->Text = "Вугляводы";
			protein_label->Text = "Бялкi";
			fat_label->Text = "Тлушчы";
			calories_label->Text = "Калорый";

			reference_title = "Даведка";
			reference =
				"У дадзеным акне адбываецца даданне прадуктаў\n" +
				"у рацыён карыстальніка.";

		}
		else if (language == "English")
		{
			this->Text = "Admin";

			menuStrip1->Items[0]->Text = "Interface";
			menuStrip1->Items[1]->Text = "Language";
			menuStrip1->Items[2]->Text = "About program";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Background color";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Reference";

			products_list_label->Text = "Diet products list";
			name_label->Text = "Name";
			carbohydrates_label->Text = "Carbohydrates";
			protein_label->Text = "Proteins";
			fat_label->Text = "Fats";
			calories_label->Text = "Calories";

			reference_title = "Reference";
			reference =
				"In this window products are added \n" +
				"into user's diet.";

		}
	}

	private: System::Void add_product_button_Click(System::Object^ sender, System::EventArgs^ e) {
		create_product({ "","","","","" });
	}
};
}
