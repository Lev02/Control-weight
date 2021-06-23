#pragma once

#include "Authentication.h"

#include <initializer_list>
#include <map>
#include <msclr\marshal_cppstd.h>
#include <random>
#include <filesystem>



namespace HealthRecommendations {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	using namespace std;

	//[year][month][42]
		/* в этом словаре год сопоставляется месяцу, а месяц
		* сопоставляется 42 числам - значенияи веса в каждом месяце
		* почему 42? потому что на календаре отображается 30 или 31 день,
		* но 6 недель, а 6*7=42
		*
		* 
		*/
	map<size_t, map<size_t, vector<float>>> year_month_current_weights;
	map<size_t, map<size_t, vector<float>>> year_month_expected_weights;
	vector<float> expected_weight_days;
	bool events_activated = true;

	/// <summary>
	/// Сводка для User
	/// </summary>
	public ref class User : public System::Windows::Forms::Form
	{
	public:
		User(String^ login, String^ language)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			InitializeMenuStrip();

			//инициализция значений
			this->current_date = DateTime::Now;
			this->current_month_label->Text = current_date.Month + "." + current_date.Year;
			this->login = login;
			this->language = language;

			//инициализация информации, ранее введенной пользоватем

			//events_activated = false служит для того, чтобы не вызывались события,
			//назначенные кнопкам
			events_activated = false;

			InitializeUserInfo();

			//инициализция изменения веса пользователя из файла
			InitializeUserWeights();

			//создание пользовательского календаря, куда пользователь будет вводить изменение веса
			InitializeUserCalendar();

			//создание календаря, где программа будет записывать ожидаемый вес
			InitializeExpectedWeightCalendar();
			UpdateExpectedWeightDays();
			UpdateExpectedWeightDictionary();
			UpdateExpectedWeightCalendar();

			//изменение языка
			change_language();

			//обновление текущего веса и цвета пользовательского календаря
			UpdateCurrentWeightCalendar();
			UpdateCurrentWeightCalendarColor();

			//снова включаем события на кнопках
			events_activated = true;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~User()
		{
			SaveUserInfo();
			SaveCurrentWeightCalendar();
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
		String^ login;
		String^ protein;
		String^ carbs;
		String^ fats;
		String^ calories;
		String^ grams;

		DateTime current_date;
		int calendar_size = 32;
		int margin = 38;


	private: System::Windows::Forms::Label^ current_weight_label;

	private: System::Windows::Forms::TextBox^ current_weight_textbox;
	private: System::Windows::Forms::Label^ desired_weight_label;
	private: System::Windows::Forms::TextBox^ desired_weight_textbox;
	private: System::Windows::Forms::Button^ calculate_button;

	private: System::Windows::Forms::Label^ limits_label;
	private: System::Windows::Forms::TextBox^ limits_textbox;

	private: System::Windows::Forms::Label^ weeks_label;
	private: System::Windows::Forms::CheckBox^ male_checkbox;
	private: System::Windows::Forms::CheckBox^ female_checkbox;
	private: System::Windows::Forms::Label^ gender_label;
	private: System::Windows::Forms::Label^ height_label;
	private: System::Windows::Forms::TextBox^ height_textbox;
	private: System::Windows::Forms::Label^ age_label;
	private: System::Windows::Forms::TextBox^ age_textbox;
	private: System::Windows::Forms::Label^ trainings_label;
	private: System::Windows::Forms::TextBox^ trainings_textbox;


	private: System::Windows::Forms::Label^ per_week_label;
	private: System::Windows::Forms::Label^ start_label;
	private: System::Windows::Forms::DateTimePicker^ start_dateTimePicker;
	private: System::Windows::Forms::Label^ current_month_label;
	private: System::Windows::Forms::Button^ next_month_button;
	private: System::Windows::Forms::Button^ previous_month_button;
private: System::Windows::Forms::Label^ current_w_label;
private: System::Windows::Forms::Label^ expected_weight_label;
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
			this->current_weight_label = (gcnew System::Windows::Forms::Label());
			this->current_weight_textbox = (gcnew System::Windows::Forms::TextBox());
			this->desired_weight_label = (gcnew System::Windows::Forms::Label());
			this->desired_weight_textbox = (gcnew System::Windows::Forms::TextBox());
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->limits_label = (gcnew System::Windows::Forms::Label());
			this->limits_textbox = (gcnew System::Windows::Forms::TextBox());
			this->weeks_label = (gcnew System::Windows::Forms::Label());
			this->male_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->female_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->gender_label = (gcnew System::Windows::Forms::Label());
			this->height_label = (gcnew System::Windows::Forms::Label());
			this->height_textbox = (gcnew System::Windows::Forms::TextBox());
			this->age_label = (gcnew System::Windows::Forms::Label());
			this->age_textbox = (gcnew System::Windows::Forms::TextBox());
			this->trainings_label = (gcnew System::Windows::Forms::Label());
			this->trainings_textbox = (gcnew System::Windows::Forms::TextBox());
			this->per_week_label = (gcnew System::Windows::Forms::Label());
			this->start_label = (gcnew System::Windows::Forms::Label());
			this->start_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->current_month_label = (gcnew System::Windows::Forms::Label());
			this->next_month_button = (gcnew System::Windows::Forms::Button());
			this->previous_month_button = (gcnew System::Windows::Forms::Button());
			this->current_w_label = (gcnew System::Windows::Forms::Label());
			this->expected_weight_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1296, 30);
			this->menuStrip1->TabIndex = 39;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// current_weight_label
			// 
			this->current_weight_label->AutoSize = true;
			this->current_weight_label->Location = System::Drawing::Point(14, 221);
			this->current_weight_label->Name = L"current_weight_label";
			this->current_weight_label->Size = System::Drawing::Size(92, 17);
			this->current_weight_label->TabIndex = 41;
			this->current_weight_label->Text = L"Текущий вес";
			// 
			// current_weight_textbox
			// 
			this->current_weight_textbox->Location = System::Drawing::Point(141, 216);
			this->current_weight_textbox->Name = L"current_weight_textbox";
			this->current_weight_textbox->Size = System::Drawing::Size(185, 22);
			this->current_weight_textbox->TabIndex = 40;
			this->current_weight_textbox->TextChanged += gcnew System::EventHandler(this, &User::current_weight_textbox_TextChanged);
			// 
			// desired_weight_label
			// 
			this->desired_weight_label->AutoSize = true;
			this->desired_weight_label->Location = System::Drawing::Point(14, 257);
			this->desired_weight_label->Name = L"desired_weight_label";
			this->desired_weight_label->Size = System::Drawing::Size(106, 17);
			this->desired_weight_label->TabIndex = 43;
			this->desired_weight_label->Text = L"Желаемый вес";
			// 
			// desired_weight_textbox
			// 
			this->desired_weight_textbox->Location = System::Drawing::Point(141, 257);
			this->desired_weight_textbox->Name = L"desired_weight_textbox";
			this->desired_weight_textbox->Size = System::Drawing::Size(185, 22);
			this->desired_weight_textbox->TabIndex = 42;
			this->desired_weight_textbox->TextChanged += gcnew System::EventHandler(this, &User::desired_weight_textbox_TextChanged);
			// 
			// calculate_button
			// 
			this->calculate_button->Location = System::Drawing::Point(17, 329);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(309, 40);
			this->calculate_button->TabIndex = 44;
			this->calculate_button->Text = L"Рассчитать оптимальную суточную диету";
			this->calculate_button->UseVisualStyleBackColor = true;
			this->calculate_button->Click += gcnew System::EventHandler(this, &User::calculate_button_Click);
			// 
			// limits_label
			// 
			this->limits_label->AutoSize = true;
			this->limits_label->Location = System::Drawing::Point(14, 292);
			this->limits_label->Name = L"limits_label";
			this->limits_label->Size = System::Drawing::Size(48, 17);
			this->limits_label->TabIndex = 46;
			this->limits_label->Text = L"Сроки";
			// 
			// limits_textbox
			// 
			this->limits_textbox->Location = System::Drawing::Point(141, 292);
			this->limits_textbox->Name = L"limits_textbox";
			this->limits_textbox->ReadOnly = true;
			this->limits_textbox->Size = System::Drawing::Size(116, 22);
			this->limits_textbox->TabIndex = 45;
			// 
			// weeks_label
			// 
			this->weeks_label->AutoSize = true;
			this->weeks_label->Location = System::Drawing::Point(263, 297);
			this->weeks_label->Name = L"weeks_label";
			this->weeks_label->Size = System::Drawing::Size(55, 17);
			this->weeks_label->TabIndex = 47;
			this->weeks_label->Text = L"недель";
			// 
			// male_checkbox
			// 
			this->male_checkbox->AutoSize = true;
			this->male_checkbox->Location = System::Drawing::Point(139, 46);
			this->male_checkbox->Name = L"male_checkbox";
			this->male_checkbox->Size = System::Drawing::Size(85, 21);
			this->male_checkbox->TabIndex = 48;
			this->male_checkbox->Text = L"мужской";
			this->male_checkbox->UseVisualStyleBackColor = true;
			this->male_checkbox->CheckedChanged += gcnew System::EventHandler(this, &User::male_checkbox_CheckedChanged);
			// 
			// female_checkbox
			// 
			this->female_checkbox->AutoSize = true;
			this->female_checkbox->Location = System::Drawing::Point(241, 46);
			this->female_checkbox->Name = L"female_checkbox";
			this->female_checkbox->Size = System::Drawing::Size(85, 21);
			this->female_checkbox->TabIndex = 49;
			this->female_checkbox->Text = L"женский";
			this->female_checkbox->UseVisualStyleBackColor = true;
			this->female_checkbox->CheckedChanged += gcnew System::EventHandler(this, &User::female_checkbox_CheckedChanged);
			// 
			// gender_label
			// 
			this->gender_label->AutoSize = true;
			this->gender_label->Location = System::Drawing::Point(14, 50);
			this->gender_label->Name = L"gender_label";
			this->gender_label->Size = System::Drawing::Size(34, 17);
			this->gender_label->TabIndex = 50;
			this->gender_label->Text = L"Пол";
			// 
			// height_label
			// 
			this->height_label->AutoSize = true;
			this->height_label->Location = System::Drawing::Point(12, 78);
			this->height_label->Name = L"height_label";
			this->height_label->Size = System::Drawing::Size(39, 17);
			this->height_label->TabIndex = 52;
			this->height_label->Text = L"Рост";
			// 
			// height_textbox
			// 
			this->height_textbox->Location = System::Drawing::Point(139, 73);
			this->height_textbox->Name = L"height_textbox";
			this->height_textbox->Size = System::Drawing::Size(185, 22);
			this->height_textbox->TabIndex = 51;
			// 
			// age_label
			// 
			this->age_label->AutoSize = true;
			this->age_label->Location = System::Drawing::Point(12, 113);
			this->age_label->Name = L"age_label";
			this->age_label->Size = System::Drawing::Size(62, 17);
			this->age_label->TabIndex = 54;
			this->age_label->Text = L"Возраст";
			// 
			// age_textbox
			// 
			this->age_textbox->Location = System::Drawing::Point(139, 108);
			this->age_textbox->Name = L"age_textbox";
			this->age_textbox->Size = System::Drawing::Size(185, 22);
			this->age_textbox->TabIndex = 53;
			// 
			// trainings_label
			// 
			this->trainings_label->AutoSize = true;
			this->trainings_label->Location = System::Drawing::Point(14, 149);
			this->trainings_label->Name = L"trainings_label";
			this->trainings_label->Size = System::Drawing::Size(87, 17);
			this->trainings_label->TabIndex = 56;
			this->trainings_label->Text = L"Тренировок";
			// 
			// trainings_textbox
			// 
			this->trainings_textbox->Location = System::Drawing::Point(141, 144);
			this->trainings_textbox->Name = L"trainings_textbox";
			this->trainings_textbox->Size = System::Drawing::Size(99, 22);
			this->trainings_textbox->TabIndex = 55;
			// 
			// per_week_label
			// 
			this->per_week_label->AutoSize = true;
			this->per_week_label->Location = System::Drawing::Point(249, 149);
			this->per_week_label->Name = L"per_week_label";
			this->per_week_label->Size = System::Drawing::Size(69, 17);
			this->per_week_label->TabIndex = 57;
			this->per_week_label->Text = L"в неделю";
			// 
			// start_label
			// 
			this->start_label->AutoSize = true;
			this->start_label->Location = System::Drawing::Point(12, 186);
			this->start_label->Name = L"start_label";
			this->start_label->Size = System::Drawing::Size(108, 17);
			this->start_label->TabIndex = 59;
			this->start_label->Text = L"Начало отчета";
			// 
			// start_dateTimePicker
			// 
			this->start_dateTimePicker->Location = System::Drawing::Point(141, 181);
			this->start_dateTimePicker->Name = L"start_dateTimePicker";
			this->start_dateTimePicker->Size = System::Drawing::Size(200, 22);
			this->start_dateTimePicker->TabIndex = 60;
			this->start_dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &User::start_dateTimePicker_ValueChanged);
			// 
			// current_month_label
			// 
			this->current_month_label->AutoSize = true;
			this->current_month_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->current_month_label->Location = System::Drawing::Point(709, 43);
			this->current_month_label->Name = L"current_month_label";
			this->current_month_label->Size = System::Drawing::Size(72, 25);
			this->current_month_label->TabIndex = 61;
			this->current_month_label->Text = L"6.2021";
			// 
			// next_month_button
			// 
			this->next_month_button->Location = System::Drawing::Point(851, 46);
			this->next_month_button->Name = L"next_month_button";
			this->next_month_button->Size = System::Drawing::Size(56, 23);
			this->next_month_button->TabIndex = 62;
			this->next_month_button->Text = L"--->";
			this->next_month_button->UseVisualStyleBackColor = true;
			this->next_month_button->Click += gcnew System::EventHandler(this, &User::next_month_button_Click);
			// 
			// previous_month_button
			// 
			this->previous_month_button->Location = System::Drawing::Point(613, 45);
			this->previous_month_button->Name = L"previous_month_button";
			this->previous_month_button->Size = System::Drawing::Size(56, 23);
			this->previous_month_button->TabIndex = 63;
			this->previous_month_button->Text = L"<--";
			this->previous_month_button->UseVisualStyleBackColor = true;
			this->previous_month_button->Click += gcnew System::EventHandler(this, &User::previous_month_button_Click);
			// 
			// current_w_label
			// 
			this->current_w_label->AutoSize = true;
			this->current_w_label->Location = System::Drawing::Point(418, 361);
			this->current_w_label->Name = L"current_w_label";
			this->current_w_label->Size = System::Drawing::Size(92, 17);
			this->current_w_label->TabIndex = 64;
			this->current_w_label->Text = L"Текущий вес";
			// 
			// expected_weight_label
			// 
			this->expected_weight_label->AutoSize = true;
			this->expected_weight_label->Location = System::Drawing::Point(839, 364);
			this->expected_weight_label->Name = L"expected_weight_label";
			this->expected_weight_label->Size = System::Drawing::Size(113, 17);
			this->expected_weight_label->TabIndex = 65;
			this->expected_weight_label->Text = L"Ожидаемый вес";
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1296, 390);
			this->Controls->Add(this->expected_weight_label);
			this->Controls->Add(this->current_w_label);
			this->Controls->Add(this->previous_month_button);
			this->Controls->Add(this->next_month_button);
			this->Controls->Add(this->current_month_label);
			this->Controls->Add(this->start_dateTimePicker);
			this->Controls->Add(this->start_label);
			this->Controls->Add(this->per_week_label);
			this->Controls->Add(this->trainings_label);
			this->Controls->Add(this->trainings_textbox);
			this->Controls->Add(this->age_label);
			this->Controls->Add(this->age_textbox);
			this->Controls->Add(this->height_label);
			this->Controls->Add(this->height_textbox);
			this->Controls->Add(this->gender_label);
			this->Controls->Add(this->female_checkbox);
			this->Controls->Add(this->male_checkbox);
			this->Controls->Add(this->weeks_label);
			this->Controls->Add(this->limits_label);
			this->Controls->Add(this->limits_textbox);
			this->Controls->Add(this->calculate_button);
			this->Controls->Add(this->desired_weight_label);
			this->Controls->Add(this->desired_weight_textbox);
			this->Controls->Add(this->current_weight_label);
			this->Controls->Add(this->current_weight_textbox);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"User";
			this->Text = L"User";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void UpdateExpectedWeightDays() {
		//проверка пустых полей
		if (current_weight_textbox->Text->Replace(" ", "") == ""
			|| desired_weight_textbox->Text->Replace (" ","") == "") {
			return;
		}

		expected_weight_days.clear();

		int weeks = stoi(marshal_as<string>(limits_textbox->Text));
		int days = weeks * 7;

		float current_weight = stoi(marshal_as<string>(current_weight_textbox->Text));
		float desired_weight = stoi(marshal_as<string>(desired_weight_textbox->Text));
		float weight_difference = current_weight - desired_weight;
		float weight_step = weight_difference / days;

		DateTime calculation_start = start_dateTimePicker->Value;

		while (current_weight >= desired_weight)
		{
			expected_weight_days.push_back(current_weight);
			current_weight -= weight_step;
		}
	}

	private: void InitializeUserWeights() {
		ifstream current_weight_file("current_weight\\" + marshal_as<string>(login->ToString()) + ".txt");
		if (!current_weight_file.is_open()) 
		{
			
		}
		else
		{
			try
			{
				/*
				* структура файла с весами человека такова:
				*
				* год
				* месяц
				* вес1
				* вес2
				* ...
				* вес42
				* год
				* месяц
				* ...
				* вес42
				*/

				string line;
				int i = 1;
				size_t year, month;
				while (getline(current_weight_file, line)) {
					if (i % 44 == 1) {
						year = stoi(line);
					}
					else if (i % 44 == 2) {
						month = stoi(line);
					}
					else {
						year_month_current_weights[year][month].push_back(stof(line));
					}
					i++;
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}	
	}

	private: void InitializeMenuStrip() {
		ToolStripMenuItem^ interfaceItem = gcnew ToolStripMenuItem("Интерфейс");
		ToolStripMenuItem^ colorItem = gcnew ToolStripMenuItem("Цвет фона");
		colorItem->Click += gcnew System::EventHandler(this, &User::colorItem_Click);
		interfaceItem->DropDownItems->Add(colorItem);

		ToolStripMenuItem^ languageItem = gcnew ToolStripMenuItem("Язык");
		auto languages = {
			 "Русский",
			 "Беларуская",
			 "English",
		};
		for (auto item : languages) {
			ToolStripMenuItem^ languageItemChild = gcnew ToolStripMenuItem(marshal_as<String^>(item));
			languageItemChild->Click += gcnew System::EventHandler(this, &User::languageItem_Click);
			languageItem->DropDownItems->Add(languageItemChild);
		}

		ToolStripMenuItem^ aboutItem = gcnew ToolStripMenuItem("О программе");
		ToolStripMenuItem^ referenceItem = gcnew ToolStripMenuItem("Справка");
		referenceItem->Click += gcnew System::EventHandler(this, &User::referenceItem_Click);
		aboutItem->DropDownItems->Add(referenceItem);


		menuStrip1->Items->Add(interfaceItem);
		menuStrip1->Items->Add(languageItem);
		menuStrip1->Items->Add(aboutItem);
	}

	private: void SaveCurrentWeightCalendar() {
		ofstream current_weights_file("current_weight\\" + marshal_as<string>(login->ToString()) + ".txt");
		size_t year, month;
		for (auto const& year_month : year_month_current_weights)
		{
			year = year_month.first;
			auto month_weights_map = year_month.second;
			
			for (auto const& month_weights : month_weights_map) {
				month = month_weights.first;
				auto weights = month_weights.second;

				current_weights_file << year << "\n";
				current_weights_file << month << "\n";
				for (float weight : weights) {
					current_weights_file << weight << "\n";
				}
			}
		}
		current_weights_file.close();
	}

	private: void SaveUserInfo() {
		ofstream user_info_file("user_info\\" + marshal_as<string>(login->ToString()) + ".txt");
		user_info_file << male_checkbox->Checked ? "1" : "0";
		user_info_file << "\n";
		user_info_file << marshal_as<string>(height_textbox->Text) << "\n";
		user_info_file << marshal_as<string>(age_textbox->Text) << "\n";
		user_info_file << marshal_as<string>(trainings_textbox->Text) << "\n";
		user_info_file << marshal_as<string>(start_dateTimePicker->Value.ToString()->Substring(0,10)) << "\n";
		user_info_file << marshal_as<string>(current_weight_textbox->Text) << "\n";
		user_info_file << marshal_as<string>(desired_weight_textbox->Text);
	}

	private: void InitializeUserInfo() {


			ifstream user_info_file("user_info\\" + marshal_as<string>(login->ToString()) + ".txt");
			if (!user_info_file.is_open())
				return;
			string line;
			vector<string> lines;
			while (getline(user_info_file, line))
			{
				lines.push_back(line);
			}
			user_info_file.close();

			if (lines.size() > 0 && lines[0] != "")
				male_checkbox->Checked = lines[0] == "1" ? true : false;
			if (lines.size() > 1 && lines[1] != "")
				height_textbox->Text = marshal_as<String^>(lines[1]);
			if (lines.size() > 2 && lines[2] != "")
			age_textbox->Text = marshal_as<String^>(lines[2]);
			if (lines.size() > 3 && lines[3] != "")
				trainings_textbox->Text = marshal_as<String^>(lines[3]);
				
			if (lines.size() > 4 && lines[4] != "") {
				int year = stoi(lines[4].substr(6, 4));
				int month = stoi(lines[4].substr(3, 2));
				int day = stoi(lines[4].substr(0, 2));
				start_dateTimePicker->Value = System::DateTime(year, month, day);
			}

			if (lines.size() > 5 && lines[5] != "")
				current_weight_textbox->Text = marshal_as<String^>(lines[5]);

			if (lines.size() > 6 && lines[6] != "")
				desired_weight_textbox->Text = marshal_as<String^>(lines[6]);

					
	}

	private: void InitializeUserCalendar() {
		int x = 270, y = 80;

		DateTime dt_start = DateTime(DateTime::Now.Year, DateTime::Now.Month, 1);
		int start = get_start_of_month(dt_start);
		int end = start + dt_start.DaysInMonth(dt_start.Year, dt_start.Month) - 1;

		for (size_t i = 1; i <= 7; i++)
		{
			Label^ weekday_label = gcnew Label();

			weekday_label->Location = System::Drawing::Point(x + margin / 4, y - margin / 2);
			weekday_label->Name = "weekday_label" + i.ToString();
			weekday_label->Size = System::Drawing::Size(26, 17);

			x += margin;
			this->Controls->Add(weekday_label);
		}

		x -= margin * 7;

		int i = 1;

		while (i <= 42)
		{
			create_calendar_textbox(Color::White, x, y, calendar_size, start, end, i,"",false);
			x += margin;
			if (i % 7 == 0)
			{
				y += margin;
				x -= margin * 7;
			}
			i++;
		}
	}

	private: void UpdateCurrentWeightCalendarColor() {
		if (expected_weight_days.size() == 0)
			return;
		int j = 1;
		for (size_t i = 0; i < this->Controls->Count; i++) {
			
			if (j >= 43)
				break;
			if (this->Controls[i]->Name == "calendar_textbox" + j.ToString())
			{
				bool empty = this->Controls[i]->Text->Replace(" ", "") == "";
				if (empty)
					this->Controls[i]->BackColor = Color::White;
				if (this->Controls[i]->Visible && !empty) {			
					for (size_t k = i+42; k < this->Controls->Count; k++)
					{
						if (this->Controls[k]->Name == "calendar_textbox" + (j + 42).ToString()) {
							float current_weight = stof(marshal_as<string>(this->Controls[i]->Text));
							float expected_weight;

							if (this->Controls[k]->Text->Replace(" ","") == "-1") {
								expected_weight = 0;
							}
							else {
								expected_weight = stof(marshal_as<string>(this->Controls[k]->Text->Replace(",",".")));
							}

							if (expected_weight <= 0.001 || current_weight <= 0.001) {
								this->Controls[i]->BackColor = Color::White;
							}
							else if (current_weight > expected_weight)
							{
								this->Controls[i]->BackColor = Color::Red;
							}
							else if (current_weight <= expected_weight) {
								this->Controls[i]->BackColor = Color::LightGreen;
							}
							break;
						}
					}
					
				}
				j++;
				
			}
			
		}
	}

	private: void UpdateCurrentWeightCalendar() {
		size_t year = this->current_date.Year;
		size_t month = this->current_date.Month;

		auto weights = year_month_current_weights[year][month];

		size_t index_of_current_weight_textbox = 0;
		for (size_t i = 0; i < this->Controls->Count; i++) {
			if (this->Controls[i]->Name == "calendar_textbox1") {
				index_of_current_weight_textbox = i;
				break;
			}
		}

		DateTime dt_start = DateTime(year, month, 1);
		int start = get_start_of_month(dt_start);
		int end = start + dt_start.DaysInMonth(dt_start.Year, dt_start.Month) - 1;

		if (weights.size() == 0) {
			for (size_t i = 1; i <= 42; i++)
			{
				if (i < start || i > end)
					year_month_current_weights[year][month].push_back(-1);
				else
					year_month_current_weights[year][month].push_back(0);
			}
			weights = year_month_current_weights[year][month];
		}

		for (size_t i = 1; i <= weights.size(); i++, index_of_current_weight_textbox++) {

			this->Controls[index_of_current_weight_textbox]->Text = weights[i - 1].ToString();
			if (weights[i-1] == -1) {
				this->Controls[index_of_current_weight_textbox]->Visible = false;
			}
			else {
				this->Controls[index_of_current_weight_textbox]->Visible = true;
			}
		}
	}

	private: int get_start_of_month(DateTime dt_start)
	{
		map<string, int> days_of_week_mp = {
			{"Monday",1},
			{"Tuesday",2},
			 {"Wednesday", 3},
			{"Thursday",4},
			{"Friday",5},
			{"Saturday",6},
			{"Sunday",7}
		};
		return days_of_week_mp[marshal_as<string>(dt_start.DayOfWeek.ToString())];
	}

	private: void UpdateExpectedWeightDictionary() {
		if (expected_weight_days.size() == 0)
			return;
		year_month_expected_weights.clear();

		DateTime start_date = start_dateTimePicker->Value;

		DateTime dt_start = DateTime(start_date.Year, start_date.Month, 1);

		//первый день начала диеты
		int start_of_month = get_start_of_month(dt_start);
		int start = start_of_month + start_date.Day - 1;

		float current_weight = stof(marshal_as<string>(current_weight_textbox->Text));
		float desired_weight = stof(marshal_as<string>(desired_weight_textbox->Text));

		//количество недель за которые произойдет похудение
		int weeks_limit = stoi(marshal_as<string>(limits_textbox->Text));
		
		int current_day_of_diet = 1;

		for (size_t i = 1; i < start_of_month; i++)
		{
			year_month_expected_weights[dt_start.Year][dt_start.Month].push_back(-1);
		}

		while (start_of_month < start) {
			year_month_expected_weights[dt_start.Year][dt_start.Month].push_back(current_weight);
			start_of_month++;
		}
			
		for (size_t i = 0; i < expected_weight_days.size(); i++)
		{
			if (start_date.Day == 1) {
				start_of_month = get_start_of_month(start_date);
				for (size_t i = 1; i < start_of_month; i++)
					year_month_expected_weights[start_date.Year][start_date.Month].push_back(-1);
			}

			year_month_expected_weights[start_date.Year][start_date.Month].push_back(expected_weight_days[i]);
			
			if (start_date.Day == start_date.DaysInMonth(start_date.Year, start_date.Month)) {
				while (year_month_expected_weights[start_date.Year][start_date.Month].size() < 42)
					year_month_expected_weights[start_date.Year][start_date.Month].push_back(-1);
			}


		
			start_date = start_date.AddDays(1);
		}
	
		for (int i = start_date.Day; i <= start_date.DaysInMonth(start_date.Year,start_date.Month); i++)
		{
			year_month_expected_weights[start_date.Year][start_date.Month].push_back(desired_weight);
		}

		while (year_month_expected_weights[start_date.Year][start_date.Month].size() < 42)
			year_month_expected_weights[start_date.Year][start_date.Month].push_back(-1);

	}

		   

	private: void UpdateExpectedWeightCalendar() {
		int index_of_first_expected_weight_textbox = 0;

		for (size_t i = 0; i < this->Controls->Count; i++)
		{
			if (this->Controls[i]->Name == "calendar_textbox43") {
				index_of_first_expected_weight_textbox = i;
				break;
			}
		}

		int year = this->current_date.Year;
		int month = this->current_date.Month;

		auto expected_weights = year_month_expected_weights[year][month];

		if (expected_weights.size() == 0) {
			for (size_t i = 1; i <= 42; i++, index_of_first_expected_weight_textbox++) {
				this->Controls[index_of_first_expected_weight_textbox]->Text = (0).ToString();
				this->Controls[index_of_first_expected_weight_textbox]->Visible = true;
			}
		}
		else if (expected_weights.size() == 42) {
			for (size_t i = 0; i < 42; i++, index_of_first_expected_weight_textbox++)
			{
				this->Controls[index_of_first_expected_weight_textbox]->Text = expected_weights[i].ToString();
				if (expected_weights[i] == -1) {
					this->Controls[index_of_first_expected_weight_textbox]->Visible = false;
				}
				else {
					this->Controls[index_of_first_expected_weight_textbox]->Visible = true;
				}
			}
		}
	}

	private: void InitializeExpectedWeightCalendar() {
		int x = 270 + margin * 9, y = 80;


		DateTime dt_start = DateTime(DateTime::Now.Year, DateTime::Now.Month, 1);
		int start = get_start_of_month(dt_start);
		int end = start + dt_start.DaysInMonth(dt_start.Year, dt_start.Month) - 1;

		for (size_t i = 8; i <= 14; i++)
		{
			Label^ weekday_label = gcnew Label();

			weekday_label->Location = System::Drawing::Point(x + margin / 4, y - margin / 2);
			weekday_label->Name = "weekday_label" + i.ToString();
			weekday_label->Size = System::Drawing::Size(26, 17);

			x += margin;
			this->Controls->Add(weekday_label);
		}

		x -= margin * 7;

		int i = 43;

		while (i <= 84)
		{
			create_calendar_textbox(Color::White, x, y, calendar_size, start, end, i,"", true);
			x += margin;
			if (i % 7 == 0)
			{
				y += margin;
				x -= margin * 7;
			}
			i++;
		}

	}

	private: void create_calendar_textbox(System::Drawing::Color^ color, int x, int y, int size, int start, int end, int textbox_counter, String^ text, bool readonly)
	{
		TextBox^ calendar_textbox = (gcnew TextBox());
		calendar_textbox->Multiline = true;
		calendar_textbox->Location = System::Drawing::Point(x, y);
		calendar_textbox->Size = System::Drawing::Size(size, size);
		calendar_textbox->Name = "calendar_textbox" + textbox_counter.ToString();
		calendar_textbox->Text = text;
		calendar_textbox->TextAlign = HorizontalAlignment::Center;
		calendar_textbox->ReadOnly = readonly;
		if (!readonly) {
			calendar_textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &User::calendar_textbox_KeyPress);
			calendar_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &User::OnKeyDown);
			calendar_textbox->TextChanged += gcnew System::EventHandler(this, &HealthRecommendations::User::OnTextChanged);
		}
		

		if (textbox_counter % 42 < start || textbox_counter % 42 > end) {
			calendar_textbox->Visible = false;
		}

		this->Controls->Add(calendar_textbox);
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

	private: void calendar_textbox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		try
		{
			TextBox^ textBox = (TextBox^)sender;
			bool ok = true;
			if (!iscntrl(e->KeyChar) && !isdigit(e->KeyChar) &&
				(e->KeyChar != '.')) {
				e->Handled = true;
			}
				
			// разрешить ввод только одной точки
			if ((e->KeyChar == '.') && textBox->Text->IndexOf('.') > -1) {
				e->Handled = true;
				
			}
				
		}
		catch (...) {}
	}

		   //метод для передвижения с помощью стрелок вправо, влево
	private: void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		bool arrow_pressed = false;
		TextBox^ textBox = (TextBox^)sender;
		string num_str = "";
		if (isdigit(textBox->Name[textBox->Name->Length - 2])) {
			num_str += textBox->Name[textBox->Name->Length - 2];
		}
		if (isdigit(textBox->Name[textBox->Name->Length - 1])) {
			num_str += textBox->Name[textBox->Name->Length - 1];
		}

		int current_selected_element = stoi(num_str);

		if (e->KeyData == Keys::Left) {
			if (current_selected_element - 1 > 0) {
				current_selected_element--;
				arrow_pressed = true;
			}
		}
		else if (e->KeyData == Keys::Right) {
			if (current_selected_element + 1 <= DateTime::Now.DaysInMonth(DateTime::Now.Year,DateTime::Now.Month)) {
				current_selected_element++;
				arrow_pressed = true;
			}
		}

		if (arrow_pressed) {
			for (size_t i = 0; i < this->Controls->Count; i++) {
				if (this->Controls[i]->Name == "calendar_textbox" + current_selected_element.ToString()) {
					this->Controls[i]->Select();
					break;
				}
			}
		}
	}

	private: void change_language()
	{
		string* days_of_week;
		if (language == "Русский")
		{
			this->Text = "Пользователь";

			menuStrip1->Items[0]->Text = "Интерфейс";
			menuStrip1->Items[1]->Text = "Язык";
			menuStrip1->Items[2]->Text = "О программе";
			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Цвет фона";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Справка";

			calories = "Калорий";
			fats = "Жиров";
			protein = "Белков";
			carbs = "Углеводов";
			grams = "гр.";

			current_weight_label->Text = "Текущий вес";
			desired_weight_label->Text = "Желаемый вес";

			current_w_label->Text = "Текущий вес";
			expected_weight_label->Text = "Ожидаемый вес";


			limits_label->Text = "Сроки";
			weeks_label->Text = "недель";

			calculate_button->Text = "Рассчитать оптимальную суточную диету";
			gender_label->Text = "Пол";
			male_checkbox->Text = "мужской";
			female_checkbox->Text = "женский";

			height_label->Text = "Рост";
			age_label->Text = "Возраст";

			trainings_label->Text = "Тренировок";
			per_week_label->Text = "в неделю";

			start_label->Text = "Начало отсчета";

			reference_title = "Справка";
			reference =
				"В данном окне происходит заполнение текущего веса \n" +
				"пользователя, расчет ожидаемого веса пользователя и \n" +
				"расчет дневного рациона на основании введенных данных.\n\n" + 
				"В левом календаре указывается текущий вес пользователя, а \n" +
				"в правом - ожидаемый вес. Если указанный пользователем вес \n" +
				"больше чем ожидаемый, то день календаря подсвечивается красным, \n" + 
				"иначе зеленым цветом. \n\n" +
				"При нажатии на кнопку 'Рассчитать оптимальную суточную диету' \n" +
				"высвечивается окно с рационом на день исходя из имеющихся продуктов. \n" +
				"Имеющиеся продукты можно дополнить в панели администратора."
				;

			days_of_week = new string[]
			{
				"Пн",
				"Вт",
				"Ср",
				"Чт",
				"Пт",
				"Сб",
				"Вс",
			};
		}
		else if (language == "Беларуская")
		{
			this->Text = "Карыстальнік";

			menuStrip1->Items[0]->Text = "Iнтэрфейс";
			menuStrip1->Items[1]->Text = "Мова";
			menuStrip1->Items[2]->Text = "Аб праграме";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Колер фону";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Даведка";

			calories = "Калорый";
			fats = "Тлушчаў";
			protein = "Бялкоў";
			carbs = "Вугляводаў";
			grams = "гр.";

			current_w_label->Text = "Бягучы вага";
			expected_weight_label->Text = "Жаданы вага";

			current_weight_label->Text = "Бягучы вага";
			desired_weight_label->Text = "Жаданы вага";
			limits_label->Text = "Тэрміны";
			weeks_label->Text = "тыдняў";

			gender_label->Text = "Падлогу";
			male_checkbox->Text = "мужчынскі";
			female_checkbox->Text = "жаночы";

			height_label->Text = "Рост";
			age_label->Text = "Узрост";

			trainings_label->Text = "Трэніровак";
			per_week_label->Text = "у тыдзень";

			start_label->Text = "Пачаткак адліку";


			reference_title = "Даведка";
			reference =
				"У дадзеным акне адбываецца запаўненне бягучага вагі \n" +
				"Карыстальніка, разлік чаканага вагі карыстальніка і \n" +
				"Разлік дзённага рацыёну на падставе уведзеных дадзеных. \n\n" +
				"У левым календары паказваецца бягучы вага карыстальніка, а \n" +
				"У правым - чаканы вагу. Калі правераны карыстальнікам вага \n" +
				"Больш чым чаканы, то дзень календара падсвятляецца чырвоным, \n" +
				"Інакш зялёным колерам. \ N \ n" +
				"Пры націску на кнопку 'Разлічыць аптымальную сутачную дыету' \n" +
				"Высвечваецца акно з рацыёнам на дзень зыходзячы з наяўных прадуктаў. \n" +
				"Наяўныя прадукты можна дапоўніць ў панэлі адміністратара."
				;

			calculate_button->Text = "Разлічыць аптымальную сутачную дыету";


			days_of_week = new string[]
			{
				"Пн",
				"Аў",
				"Ср",
				"Чц",
				"Пт",
				"Сб",
				"Нд",
			};
		}
		else if (language == "English")
		{
			this->Text = "User";

			menuStrip1->Items[0]->Text = "Interface";
			menuStrip1->Items[1]->Text = "Language";
			menuStrip1->Items[2]->Text = "About program";

			((ToolStripMenuItem^)menuStrip1->Items[0])->DropDownItems[0]->Text = "Background color";
			((ToolStripMenuItem^)menuStrip1->Items[2])->DropDownItems[0]->Text = "Reference";

			calories = "Calories";
			fats = "Fats";
			protein = "Proteins";
			carbs = "Carbs";
			grams = "gr.";

			current_w_label->Text = "Current weight";
			expected_weight_label->Text = "Expected weight";

			current_weight_label->Text = "Current weight";
			desired_weight_label->Text = "Desired weight";
			limits_label->Text = "Timing";
			weeks_label->Text = "weeks";

			gender_label->Text = "Gender";
			male_checkbox->Text = "male";
			female_checkbox->Text = "female";

			height_label->Text = "Height";
			age_label->Text = "Age";

			calculate_button->Text = "Calculate the optimal daily diet";

			trainings_label->Text = "Trainings";
			per_week_label->Text = "per week";

			start_label->Text = "Start date";


			reference_title = "Reference";
			reference =
				"This window is filling the current weight \n" +
				"user, calculating the expected user weight and \n" +
				"calculation of the daily ration based on the entered data. \n\n" +
				"The left calendar shows the user's current weight, and \n" +
				"on the right is the expected weight. If the user-specified weight \n" +
				"more than expected, the day of the calendar is highlighted in red, \n" +
				"otherwise in green. \ n \ n" +
				"By clicking on the button 'Calculate the optimal daily diet' \n" +
				"a window is displayed with the daily ration based on the available products. \n" +
				"Available products can be updated in the admin panel."
				;

			days_of_week = new string[]
			{
				"Mo",
				"Tu",
				"We",
				"Th",
				"Fr",
				"Sa",
				"Su",
			};
		}

		int j = 1;

		for (size_t i = 0; i < this->Controls->Count; i++)
		{
			if (this->Controls[i]->Name->ToString() == ("weekday_label" + j.ToString()))
			{
				this->Controls[i]->Text = marshal_as<String^>(days_of_week[(j - 1) % 7]);
				j++;
			}
		}
	}

private: System::Void calculate_button_Click(System::Object^ sender, System::EventArgs^ e) {

	int age = stoi(marshal_as<string>(age_textbox->Text));
	int height = stoi(marshal_as<string>(height_textbox->Text));
	int weight = stoi(marshal_as<string>(current_weight_textbox->Text));

	float calories;

	int trainings = stoi(marshal_as<string>(trainings_textbox->Text));

	if (male_checkbox->Checked) {
		calories = (10 * weight) + (6.25 * height) - (5 * age) + 5;
	}
	else {
		calories = (10 * weight) + (6.25 * height) - (5 * age) - 161;
	}

	if (trainings == 0)
		calories *= 1.2;
	if (trainings >= 1 && trainings < 3)
		calories *= 1.375;
	if (trainings >= 3 && trainings <= 5)
		calories *= 1.55;
	if (trainings >= 6 && trainings <= 7)
		calories *= 1.725;
	if (trainings >= 7)
		calories *= 2;

	MessageBox::Show(get_recommendations(calories));
}

	   private: String^ get_recommendations(float calories_count) {
		   vector<vector<string>> products_info;

		   string products_folder_path = "products";

		   //проход по каждому файлу в папке products_folder_path
		   for (const auto& dirEntry : std::filesystem::recursive_directory_iterator::recursive_directory_iterator(products_folder_path)) {
			   ifstream product(dirEntry.path());
			   string line;
			   vector<string> product_info;
			   while (getline(product, line)) {
				   product_info.emplace_back(line);
			   }
			   products_info.push_back(product_info);
		   }

		   if (products_info.size() < 1) {
			   MessageBox::Show("Ошибка! В рационе менее 6 продуктов.");
		   }

		   //выбираем 5 продуктов на день радномно
		   random_device dev;
		   mt19937 rng(dev());
		   uniform_int_distribution<mt19937::result_type> distribution(1, products_info.size());

		   vector<vector<string>> chosen_products;
		   vector<int> rand_nums;
		   bool* used = new bool[products_info.size()]{};
		   int rand_num;
		   for (size_t i = 0; i < min(products_info.size(),6); i++)
		   {
			   do {
				   rand_num = distribution(rng);
			   } while (used[rand_num - 1]);
			   used[rand_num - 1] = true;
			   chosen_products.push_back(products_info[rand_num - 1]);
		   }

		   delete[] used;

		   float current_calories = 0;
		   vector<float> amount(6);


		   
		   //берём три пары продуктов
		   bool first_product;
		   String^ recommendations = "";

		   float total_fat = 0;
		   float total_protein = 0;
		   float total_carbs = 0;


		   for (size_t i = 1; i <= 3; i++)
		   {
			   recommendations += i.ToString() + "\n\n";

			   float calories_per_pair = stof(chosen_products[i * 2 - 2][4]) + stof(chosen_products[i * 2 - 1][4]);
			   amount[i * 2 - 2] = (calories_count / 3) / calories_per_pair * 100;
			   amount[i * 2 - 1] = amount[i * 2 - 2];

			   
			   total_fat += stof(chosen_products[i * 2 - 2][1]);
			   total_protein += stof(chosen_products[i * 2 - 2][2]);
			   total_carbs += stof(chosen_products[i * 2 - 2][3]);

			   total_fat += stof(chosen_products[i * 2 - 1][1]);
			   total_protein += stof(chosen_products[i * 2 - 1][2]);
			   total_carbs += stof(chosen_products[i * 2 - 1][3]);

			   recommendations += marshal_as<String^>(chosen_products[i * 2 - 2][0]);
			   recommendations += " " + amount[i * 2 - 2].ToString();
			   recommendations += grams + "\n";

			   recommendations += marshal_as<String^>(chosen_products[i * 2 - 1][0]);
			   recommendations += " " + amount[i*2-1].ToString();
			   recommendations += grams + "\n";

			   recommendations += "\n";
		   }

		   recommendations += carbs + ": " + total_carbs.ToString() + "\n";
		   recommendations += fats + ": " + total_fat.ToString() + "\n";
		   recommendations += protein + ": " + total_protein.ToString() + "\n";
		   recommendations += calories + ": " + calories_count.ToString() + "\n";

		   return recommendations;
	   }

private: System::Void male_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (male_checkbox->Checked)
	{
		female_checkbox->Checked = false;
	}
	else
	{
		female_checkbox->Checked = true;
	}
}
private: System::Void female_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (female_checkbox->Checked)
	{
		male_checkbox->Checked = false;
	}
	else
	{
		male_checkbox->Checked = true;
	}
}

private: System::Void current_weight_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isNumber(current_weight_textbox->Text) && isNumber(desired_weight_textbox->Text)) {
		int current_weight = stoi(marshal_as<string>(current_weight_textbox->Text));
		int desired_weight = stoi(marshal_as<string>(desired_weight_textbox->Text));

		if (desired_weight > current_weight) {
			desired_weight = current_weight;
			desired_weight_textbox->Text = desired_weight.ToString();
		}

		limits_textbox->Text = ((current_weight-desired_weight) * 2).ToString();

		if (events_activated) {
			UpdateExpectedWeightDays();
			UpdateExpectedWeightDictionary();
			UpdateExpectedWeightCalendar();
		}
		
	}
}
private: System::Void desired_weight_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isNumber(current_weight_textbox->Text) && isNumber(desired_weight_textbox->Text)) {
		int current_weight = stoi(marshal_as<string>(current_weight_textbox->Text));
		int desired_weight = stoi(marshal_as<string>(desired_weight_textbox->Text));

		if (current_weight < desired_weight) {
			current_weight = desired_weight;
			current_weight_textbox->Text = current_weight.ToString();
		}

		limits_textbox->Text = ((current_weight-desired_weight) * 2).ToString();

		if (events_activated) {
			UpdateExpectedWeightDays();
			UpdateExpectedWeightDictionary();
			UpdateExpectedWeightCalendar();
		}
	}
}

bool isNumber(String^ str)
	   {
		   try
		   {
			   if (str->Length == 0)
				   return false;
			   stof(marshal_as<string>(str));
			   return true;
		   }
		   catch (...)
		   {
			   return false;
		   }
	   }

private: System::Void start_dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (events_activated) {
		UpdateExpectedWeightDays();
		UpdateExpectedWeightDictionary();
		UpdateExpectedWeightCalendar();
	}
	
}

private: System::Void previous_month_button_Click(System::Object^ sender, System::EventArgs^ e) {
	current_date = current_date.AddMonths(-1);
	this->current_month_label->Text = current_date.Month + "." + current_date.Year;
	UpdateExpectedWeightCalendar();
	UpdateCurrentWeightCalendar();	
}
private: System::Void next_month_button_Click(System::Object^ sender, System::EventArgs^ e) {
	current_date = current_date.AddMonths(1);
	this->current_month_label->Text = current_date.Month + "." + current_date.Year;
	UpdateExpectedWeightCalendar();
	UpdateCurrentWeightCalendar();	
}

	   void OnTextChanged(System::Object^ sender, System::EventArgs^ e)
	   {
		   if (events_activated) {
			   //обновление цвета календаря
			   UpdateCurrentWeightCalendarColor();

			   //проверка инициализированности даты
			   //получение номера вызвранного текстбокса
			   try
			   {
				   string text = marshal_as<string>(((TextBox^)sender)->Name);
				   string textbox_num = "";
				   if (isdigit(text[text.size() - 2]))
					   textbox_num += text[text.size() - 2];
				   textbox_num += text[text.size() - 1];

				   //получение значения текстбокса
				   float value = stof(marshal_as<string>(((TextBox^)sender)->Text));

				   //ввод значения в словарь
				   year_month_current_weights[current_date.Year][current_date.Month][stoi(textbox_num)-1] = value;
			   } catch (...)
			   { }
			   
		   }
				 
	   }
};
}



