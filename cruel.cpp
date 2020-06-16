#include <iostream> //библиотека ввода и ввывода
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <list>
#include <mutex>
#include <algorithm>
using namespace std;
#include "SimpleTimer.h"
mutex mtx;
mutex mtxtwo;
void Print() {
	mtxtwo.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	mtx.lock();
	for (int i = 0; i < 5;i++) {
		for (int i = 0; i < 10;i++) {
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx.unlock();
	mtxtwo.unlock();
}
void Print2() {
	mtx.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	mtxtwo.lock();
	for (int i = 0; i < 5; i++) {
		for (int i = 0; i < 10; i++) {
			cout << '#';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx.unlock();
	mtxtwo.unlock();
}
class Person {
public:Person(string name, double score,int age) {
	this->Name = name;
	this->Score = score;
	this->Age = age;
}
	   bool operator()(const Person &p) {
		   return  p.Score > 180;
	 }
	string Name;
	double Score;
	int Age;
};
class Point {
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	};
	int x, y;
};
int main() {
	setlocale(LC_ALL, "ru");
	/*vector<Person>vs{
	Person("Вася",181,22),
	Person("Петя",30,25),
	Person("Маша",179,24),
	Person("Даша",200,23),
	Person("Катя",198,30),
	Person("Андрей",181,40),
	Person("Сергей",50,32),
	Person("Иван",150,18),
	Person("Иван",199,19),
	Person("Петя",10,53)
	};*/
	SimpleTimer timer;
	thread t1(Print);
	thread t2(Print2);
	t1.join();
	t2.join();
	return 0;
}
//functor/functions(entity that supports operator()) -- predicates(functions/functors which return boolean value)
//namespace x{foo(){}} namespace z{foo()} - x::foo();z::foo();
/*#include <thread>-работа с потоками, "this_thread"::x-x=метод пространства имен this_thread--get_id(),sleep_for(chrono::milliseconds(z)),
#include <chrono>-работа современем-thread name(pointeronFunction,param1,param2);-object-detach()-обрывПотока if mainthread ended,join()-waiting of ending ofother thread
thread t(([&x](){x=Sum(2,5);});либо thread t(DoWork, ref(q));-"std::ref(x)"возвращение результата из thread, если функция/метод/параметр впотоке принимает ссылку на объект-
#include <mutex> -synchronisingthreads-mutex name;-lock(),unlock(),lock_guard<t>name();*/
/*"enum name{};"-enum PCstate {OFF, ON, SLEEP,PAIN=1000}; if(PCstate::ON){}; -перечисляемый набор констант
директивыПредпроцессора #define DEBUG-const, #define p 3.14- autoreplace
typedef std::vector<int> vector; -replace, new alias for existedtypes
#ifdef DEBUG OR #ifndef DEBUG-inverted-кодinsideworks if DEBUGwill defined-#else OR #elseif OR #if DEBUG>4- #endif
#pragma once -protectfromloopinclude-*/
/*лямбда-анонимная функция [](){};-можнопередеватьеёв качестве параметра,присваивать DoWork(vc, [](int a){sth}
[]-для работы с переменной в ВНЕШНЕМконтексте-[&p]- [&] чтобы захватить в констекс все переменные по ссылке(можно прочитать и изменить)
[=]-чтобы захватить в контекстпеременные по значению(прочитать можно, изменить нельзя-т.к работаемскопией)
[=]()mutable{};-"mutable"-поведениелямбды будто по ссылке(можем менятьdataвнутри лямбды) но переменные вне контекста сохранят значения
class x{void namea() {auto f = [this]() {this->namea();};f();}; - [this] захватили весь класс
thread t(&MyClass::DoWork,m); либо так-первыйП=метод, второйП=объект, третийП=параметры метода*/
//int*pa=new int-int[x] fordynamicArray-; delete pa; -"new"-addMemory,"delete"-clearuselessMemory-pa=NULL;-pa=nullptr;-обнулили pointer
/*STL library #include<memory> -auto_ptr <type> x;-затираетдругиеPtr-unique_ptr <type> x;-"move()","swap()"-
shared_ptr<type>x;-possess the samedata together-int* arr = new int[SIZE];shared_ptr<int[]> ptr(arr);-
STL контейнер #include<list>-реализация ДВУСВЯЗНОГО спискаlist<type>name; list<type>::iterator x;-sort(),pop_back,pop_front()-delete-,reverse(),unique(),insert(),erase(),remove(),assign(x,z)-x=count,z=replace on-,
STL	контейнер #include<forward_list>-реализация ОДНОСВЯЗНОГО списка forward_list<type> name; -insert_after(),erase_after(),before_begin(), etc
STL контейнер #include<deque>- deque<type> name;-deque<type>::iterator x;- тежеметоды
STL контейнер #include<set> -на основе ,БИНАРНОГО древа-stores uniquevalue- set<type> name; multiset<type> name;-value can be repeated, upper_bound(x),lower_bound(x), equal_range(x)-arrчиселот u_b до l_b -
STL контейнер #include<map> на осн БИНАРНОГО древа -stores uniquekey and value-sortingbased on key-map<t1,t2> name;-std::pair<t1,t2> name;- multimap<t1,t2> name;-key can be repeated- -addPair "insert(make_pair(t1,t2));","emplace(t1,t2);","insert(pair<t1,t2>(x1,x2))"
STL адаптеры-контейнеров -limitfunctional to adapter- #include<stack> "LastIN-FirstOut" #include<queue>-"FirstIN-FirstOut" -priority_queue<>n;-size(),push(),pop(),swap(),back(),emplace(),empty(),front()
STL algorithms -#Include <algorithm>,#include<numeric> -count_if(first,last,predicate),find(F,L,value),find_if(F,L,Pred),find_if_not(F,L,P),copy(F,L,Destination),copy_if(F,L,D,Pred),
remove(F,L,value)-moveApproprElements TotheEnd of Collection and return Iterator-,remove_if(F,L,Pred),max_element(F,L),min_element(F,L),accumulate(F,L,startValue),equal(F,L,F2,L2),
 //include#<functional> function<type()> name;
 void DoWork(vector<int>&vc, function<void(int)>f) {for (auto el : vc) {f(el);}
void DoWork(vector<int>&vc, vector<function<void(int)>>funcVector){for (auto el : vc) {for (auto &fel : funcVector) {fel(el);}	}}
 vector<function<void(int) >> fVector = { Bar,Foo }; DoWork(vc, fVector); -массив объектов function
STL library #include<vector>-for DYNAMIC arrays-"vector<type> name;"-size(),push_back(),push_front(),clear(),capacity(),reserve(),shrink_to_fit(),empty(),resize() etc.
	iterator STL "vector<type>::type_iterator name;"-vector<int> mine;it=name.begin();it++; cout<<*it; ,end(),-cbegin(),cend()-для const_iterator
	"vector<type>reverse_iterator name;"-rbegin(),rend()- righttoleft
	if cout<<*(it+3); don't work, needuse "advance(iterator,shift);"-insert(x,a) xiterator=куда,a=число-erase()
STL array #include<array>-for STATIC arrays,-array<type,x>;-x=size - fill(), те же методы	*/
/*"for(object var :collection_to_loop){}"-for(auto x:arr){}-var=куда,:=перебор элементов,collection=где;foreach=range based цикл */
/*#include<string>- getline(cin, x); -"getline()"-to read all line- "length()"-to get the length of string
 "substr(9,7)"-1st parameter is begginig of string, 2nd iscountof characters afterit
 "swap(x)"-who willbe swapped=x-"find("")";-find thefirst occurrence and return its index-"rfind("")"-reverse, find thefirst occurrence from right
 "erase(x)"-starting=x willbe erased-"replace(x,a,"b")"-starting=x,длина=a,what willbe placed="b"-"insert(x,"z")"-starting=x, what willbe inserted="z"
 concatenationСтрок-"strcat_s(x,y)"*/
 //union{} - syntax,подобен классу- sharing local memory between different value, but in one moment contains only one data
 /* ofstream for writing to a file, ifstream for reading from a file
 #include<fstream>-it works with files- ofstream xFile;- xFile.open("tuna.txt");-what file will be associated with that object-xFile.close();-для выгрузки памяти
 (fin.read((char*)& pnt, sizeof(Point)));-read/write from Point pnt,sizeof(x)
 ofstream xFile("beefjerky.txt"); if(xFile.is_open()){} -".is_open()"-check if object was associated with file correctly
 -ДоступныСостояния- fstream::in-read-,fstream::out-write-,fstream::app-appendData- 
-overload "<<"-ostream& operator<<(ostream&os, const Point& p) {os << p.x << " " << p.y << " " << p.z << endl;return os;}
-overload ">>""-istream& operator>>(istream& is, Point& pp) {is >> pp.x >> pp.y >> pp.z;return is;
} */
 /*exceptions-is a way of handling errors-consist "try{}" block -where the error might occur and afterit-"catch(int x){}" block-what to do if it is indeed an error
 try{if (sonsAge>momsAge){throw 99;}}catch{} -throw something-means error
 try{}catch(...){}- general error message "(...)"*/
 /* template<>  -specialized template- class Spunky<char> {public:Spunky(char x)} *как case: в switch*
  template <class T> -regular template-впереди каждой функции-x-, which needs in generic type T, and black generic datatype after class name <T>
 x T Bucky<T>::bigger(){refirst>second?first:second);} and -whenever make object,we need tell toit, what type of data substitute for T- Bucky <int> bo(55, 70);*/
 //return(a<=b?a:b) где ?a-then- 1stcase, :b-else-2ndcase
 /*template definition - "template <class bucky>" bucky is template,just generic type of data to work with any type
 template <class bucky> bucky addCrap(bucky a,bucky b) {return a+b;} - but for different inputs as int x,float z we need use more than 1 template
 template <class FIRST, class SECOND> FIRST smaller(FIRST a, SECOND b){} -где FIRST return type функции*/
 /*  -pure- virtual function - virtual void attack()=0;  - without body"{}", and =0 -any derived class needs in overwrite this function
  abstract classes are classes with pure virtual function in them - Enemy           */
  /*Polymorphism- special inheritance, when derived classes have its own specific traits
  Ninja n;Monster m;Enemy *enemy1 =&n;Enemy *enemy2 =&m;enemy1->setAttackPower(29);enemy2->setAttackPower(99);n.attack();m.attack();
  "virtual" -template of function in base class- virtual void attack(){} - using the same function but with different results enemy1->attack(); enemy2->attack();
  "override"-to makesure, that this is derivedF with same signature-void atack() override{}-or it will be not polymorphicF
  class name:public virtual basecname{}; -для ромбовидного inheritance*/
  /*C++ inheritance- base classturn((all traits in it)"Mother" and derived class(is going to get all traits)"Daughter"
  -Daughter.h- class Daughter: public  Mother{}; -inheritanceof all variables and functions in Mother class(only mentioned in public: and protected:)
  it involves constructor and deconstructor of base class, BUT only invoke him- without inheriting itself.           */
  /*Sally::Sally(){}  constructor - для Sally.cpp -whenever my object is created, constructor runs
	  class Sally{ public: Sally();  }; - для Sally.h(header)
	Sally::~Sally(){} deconstructor - Sally.cpp -whenever my object is destroyed(всегда после завершения программы), deconstructor runs
	  class Sally{ public: ~Sally(); }; - Sally.h
	MyClass(const MyClass &other) { -constructor for COPYING
	this->Size = other.Size; this->data = new int[other.Size]; for (int i = 0; i < other.Size; i++) {this->data[i] = other.data[i];}
	DELEGAT constructor- Human(string namex){this->name = namex;this->age = 0;this->weight=0;}
	Human(string namex,int agex):Human(namex) {this->age =agex;}*/
  //a=p*pow(1+r,day); #include <cmath> для pow()
 //switch(age){    case 16: cout<<sdasd; break; default: cout<<bb;
 // #include <cstdlib>  rand(); srand(28) или +#include <ctime> srand(time(0)); где 0 это секунды изменения между числом
 //function prototypes in header- if functions described above its вызова
 // unary scope resolution operator (for global operator)   ::x
 /* int someArray[3]={12,23,5} (array initializer list); cout<<array[index];  [] для обозначения массива
  multy-dimensional array[2][3] = 6 элементов(first -rows, second - columns)
 int sally[2][3]={{1,2,3},{7,8,9}}; cout<<sally[0][2]; [0]-номер строки(индекс) ; [2] - элемент(номер столбика в строчке= индекс)
  "at();"-где () для индекса массива  */
  /*		*& - ССЫЛКА на УКАЗАТЕЛЬ, т.к указатель указывает на объекты, ссылка- не объект
  &fish, где & - address operator, it shows address - &x=b -reference(&x=&b), (x=b)
    int *xPointer, *-pointer, -xPointer contains memory address as a value, т.к 0x61fe14 not int,string or float!
  *xP=&bo--xP=&bo--*xP=bo;  sizeof(some function, variable) размер в байтах	*/
  // returntype classname::functionname(){}   void Sally::printCrap(){} - it means printCrap() belongs to the Sally class(для Sally.cpp)
  // Sally bo; bo.printCrap(); "." for object- через объект bo получаем доступ к функциям, переменным внутри класса Sally
  // Sally *sallyPointer=&bo; - где 'Sally' type of data(class - тоже тип переменной)
  //arrow member selection operator "->" for pointer; sallyPointer->printCrap();
  /* for regular class objects - regular functions and variables <=> if we build constant class object we work with constant functions
	void Sally::printSh2()const{}    */
/*member initializer syntax - when we use initializers in constructor, then we don't type any variables into body
Sally::Sally(int a, int b): regVar(a), constVar(b){} - startwith : makealist variable(value) */
//-composition more strict -невозможно создать объект внутреннего privateкласса в другом классе (private описание other class inside your class(objects,variables) - remember member initializer list)
//-aggregation less strict -можносоздатьобъект класса в другом классе(любое описание,private объект класса name в nameX,обращение к методам name в nameX)
/* friendlyfunction that can access some class - friend type nameF(Class objectforF);
class StankFist{public :.. private: friend void stinkysFriend(StankFist &sfo);};
OR for friendlymethods-friend type Class::method();
class x{public:friend nameZclass;} -to make friendship between classess,на уровне дружественного класса nameZclass can access to x*/
/* Print1option : keyword "this"   this->h-"this->"Constpointer на текущий объект текущего класса-
// Print2option : (*this).h                          */
/* operator overloading - перегрузка операторов для работы с объектами -перегружаем(+,-,=,==,!=,/,>,<,>=,<=*)-name type operator==(){};
-дляПрисваивания"="-MyClass& operator=(const MyClass &other) {cout << "Вызвался оператор =" << this << endl;this->Size = other.Size;
if (this->data != nullptr) {delete[] this->data;}this->data = new int[other.Size];
for (int i = 0; i < other.Size; i++){this->data[i] = other.data[i];}return *this;"
чтобыКорректно c=b=a -c.operator=(b.operator=(a));-тип MyClass& т.к возвращаем ссылку/самобъект "*this"
-дляБулевых(==,!=,>,< т.д)-bool operator!=(const name &other ) {return !(this->x == other.x && this->y == other.y);-bool res=a==b;}
-для(+,-,*,/)-Point operator+(const Point& other) {Point temp;
temp.x = this->x + other.x;temp.y = this->y + other.y;return temp;} -Point c=a+b;-
-дляPostfix(++,--) Point& operator++(int value) {Point temp(*this);this->x++;this->y++;return temp;}
-int& operator[](int x){return arr[x];}
-умныйуказатель*-T& operator*() {return *ptr;}*/
// classkeyword "protected:" -anything inside this class, any "friend" and base classes
//"static" variable,method-не привязана к объекту,создается на уровне класса- -classname{public:static int Count;} int classname::Count=0;-afterclass- static int name(){};
