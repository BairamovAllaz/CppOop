#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age	//Ïðèíèìàåìûå ïåðåìåòðû êîíñòðóêòîðà Human
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual std::ostream& print(std::ostream& os)
	{
		os << last_name << " " << first_name << " " << age << " age" << endl;
		return os;
	}

	virtual std::ofstream& print(std::ofstream& os) {
		os << left;
		os.width(10);
		os << right;
		os << last_name;
		os.width(10);
		os << right;
		os << first_name;
		os << right;
		os.width(7);
		os << age;
		return os;
	}

	virtual std::ifstream& scan(std::ifstream& in) {
		in >> last_name >> first_name >> age;
		return in;
	}
};

std::ostream& operator <<(std::ostream& os,Human& obj) {
	return obj.print(os);
}

std::ofstream& operator <<(std::ofstream& os, Human& obj) {
	return obj.print(os);
}

std::ifstream& operator >>(std::ifstream& in, Human& obj) {
	return obj.scan(in);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)
	{
		Human::print(os);
		os << speciality << " " << group << " " << rating << " " << attendance << endl;
		return os;
	}

	std::ofstream& print(std::ofstream& os) {
		Human::print(os) << " ";
		os.width(15);
		os << right;
		os << speciality;
		os.width(8);
		os << group;
		os << right;
		os.width(8);
		os << rating;
		os.width(8); 
		os << attendance; 
		return os;
	}

	std::ifstream& scan(std::ifstream& in) {
		Human::scan(in);
		in >> speciality >> group >> rating >> attendance;
		return in;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//				Constructor
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//					Methods
	std::ostream& print(std::ostream &os)
	{
		Human::print(os);
		os << speciality << " " << experience << endl;
		return os;
	}

	std::ofstream& print(std::ofstream& os) {
		Human::print(os) << " ";
		os.width(18);
		os << right;
		os << speciality;
		os.width(10);
		os << experience;
		return os;
	}

	std::ifstream& scan(std::ifstream& in) {
		Human::scan(in);
		in >> speciality >> experience;
		return in;
	}

};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//						Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//						Methods:
	std::ostream& print(std::ostream &os)
	{
		Student::print(os);
		os << subject << endl;
		return os;
	}

	std::ofstream& print(std::ofstream& os) {
		Student::print(os) << " ";
		os << left;
		os.width(15);
		os << subject;
		return os;
	}

	std::ifstream& scan(std::ifstream& in) {
		Student::scan(in);
		in >> subject; 
		return in;
	}

};


//#define INHERITANCE_CHECK
//#define WRITE_TO_FILE
//#define READ_FROM_FILE

Human* newtype(const std::string& st) {
	if (st.find("class Student") != std::string::npos) {
		return new Student("", "", 0, "", "", 0, 0);
	}
	if (st.find("class Teacher") != std::string::npos) {
		return new Teacher("", "", 0, "", 0);
	}
	if (st.find("class Graduate") != std::string::npos) {
		return new Graduate("", "", 0, "", "", 0, 0, "");
	}
}


int main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Connor", "John", 18);
	human.print();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
	stud.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();

	Graduate grad("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How to catch Heizenberg");
	grad.print();
#endif // INHERITANCE_CHECK

	
#ifdef WRITE_TO_FILE

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How-to-catch-Heizenberg"),
		new Student("Vercetti", "Tomas", 30, "Citybusiness", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 55, "Weaponsdistribution", 30),
		new Student("Montana", "Antonio", 30, "Cryminalistic", "Vice", 90, 80)
	};


	std::ofstream fout("test.txt");
	
	if (fout.is_open()) {
		int size = sizeof(group) / sizeof(group[0]);

		for (size_t i = 0; i < size; i++)
		{
			fout << string((typeid(*group[i]).name())) << ":";
			fout << *group[i] << endl;
		}
	}
	else {
		cout << "File is not find" << endl;
	}

	fout.close();

	system("start notepad test.txt");


	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // WRITE_TO_FILE


#ifdef READ_FROM_FILE
<<<<<<< HEAD
=======


>>>>>>> edde3841cbdd1ace963cec2a2b9a4952f5850456
	std::ifstream fin("test.txt");
	int size = 0;
	Human** group = nullptr;
	if (fin.is_open()) {
		std::string buffer;
		
		for (;!fin.eof();++size)
		{
			std::getline(fin, buffer);
		}
		--size;
		group = new Human*[size]{};
		cout << fin.tellg() << endl;
		fin.clear(); 
		fin.seekg(0);
		cout << fin.tellg() << endl;
		cout << size << endl;
		for (int i = 0; i < size; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = newtype(buffer);
			fin >> *group[i];
		}
		fin.close();
	}
	else {
		cout << "File is not found!" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < size; i++)
	{
		delete group[i];
	}
	delete[] group;
#endif // READ_FROM_FILE
	return 0;
}
