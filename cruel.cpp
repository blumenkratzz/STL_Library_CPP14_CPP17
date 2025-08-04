#include <iostream> //библиотека ввода и ввывода
#include <vector>
#include <chrono>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <iterator>
#include <type_traits>
#include <functional>
#include <cassert>
#include <thread>
#include <algorithm>
using namespace std;
#include "SimpleTimer.h"
extern int gpntb;
class C {
public:
	C(int x,int y,int* z){
		this->pointer = z;
	}
	C(int be):g(be){
	}
	C(){}
	~C(
	){ 
			delete[] pointer;
		
	}
	int* pointer=nullptr;
	int g=5;
};
template<class G>
typename remove_reference<G>::type&& mov(G&&x){
	return static_cast<remove_reference_t<G>&&>(x);
}
template<class T>
T&& forwa(remove_reference_t<T>&x){
	return static_cast<T&&>(x);
}
template<typename C>
decltype(auto) gbi(C& c, size_t i) { return c[i]; }
constexpr int fib(int n) {
if (n > 1) {
	return fib(n - 1) + fib(n - 2);}if (n == 1) { return 1; }if (n == 0) { return 0; }}
template<bool B,typename T>
struct enable_if_{};
template<typename T>
struct enable_if_<true, T> { typedef T type; };
template<typename T>
struct is_class_ {
private:
	template<typename H>
	static int f(int H::* p) { return 0; }
	template<typename...>
	static char f(...) { return 0; }
public:
	static const bool value = is_same<decltype(f<T>(5)), int>::value;
	//sizeof(f<T>(nullptr))  == sizeof(int);
};
template<typename...Args>
struct tuple_{};
template<typename Head, typename...Tail>
struct tuple_<Head,Tail...>:tuple_<Tail...>{
	tuple_(Head h, Tail...tail):tuple_<Tail...>(tail...),head_(h){}
	typedef tuple_<Tail...> base_type;
	typedef Head value_type;
	base_type& base = *this;
		//static_cast<base_type&>(*this);
	Head head_;
};
template<>
struct tuple_<>{};
template<class C, class...Args>
struct has_method_construct_{
private:
	template<typename...>
	static char f(...) { return 0; }
	template<typename T, typename...Kwargs>
	decltype(declval<T>().construct(declval<Kwargs>()...), int()) f(int) { return 0; }
public:
	static const bool value=sizeof(f<C,Args...>(5))==sizeof(int);

};
template<class C, class...Args>
struct is_constructible_ {
private:
	template<typename...>static char f(...) { return 0; }
	template<typename T, typename...Kwargs>
	static decltype(T(declval<Kwargs>()...), int()) f(int) { return 0; }
public:static const bool value;
};
template<typename C>
struct is_nothrow_move_constructible_{
private:template<typename...>
	static char f(...) { return 0; }
	template<typename H>
	static typename conditional<noexcept(H(move(declval<H>()))), int, char>::type f(int x)
	{return 0;}
public:static const bool value = sizeof(f<C>(5)) == sizeof(int);
};
template<typename T>
typename conditional<is_nothrow_move_constructible_<T>::value, T&&, const T&>::type move_if_noexcept_(T& x)
{return move(x);}
template<class Base,class Derived>
struct Helper{
	operator Derived*() {};
	operator Base*  () const {};
};
template<class Base,class Derived>
struct is_base_of_{
private:
template<class T>
static int f(Derived*, T) {};
static char f(Base*, int);
public:
static const bool value = sizeof(f(Helper<Base, Derived>(), int())) == sizeof(int);
};
template<class u,class v>
struct common_type_{
	typedef decltype(true ? declval<u>() : declval<v>()) type;
};
struct POD {
	int i;
	double d;
	char c;
};
struct fr {
	auto get() { return this; }
};
int fruit(double xex) { return 3.7; };
int something(int) { return 'a'; };
class tr {
private:int a = 985;
	   int b = 177; int c = 888; double d = 756; double x = 444;
};
int main(int argc, char*argv[]) {
	setlocale(LC_ALL, "ru");
	allocator<string> mine;
	int*p=new int[(sizeof C)*4];
	C*ptr=new(p) C(5,10,p); //placement new
	ptr->~C(); 
	ptr = nullptr;
	cout << typeid(mine).name() << endl;
	cout<<typeid(allocator<string>::value_type).name()<<endl;
	list<int> m;
	multimap<string, int> mas;
	mas.insert(make_pair("abc",4));
	mas.insert(make_pair("abc", 10));
	mas.insert(make_pair("abc", 203));
	mas.insert(make_pair("abc", 5));
	mas.insert(make_pair("abd", 106));
	cout << mas.size() << endl;
	auto coma=mas.equal_range("abc");
	multimap<string, int>::iterator itr = coma.second;
	cout<<"fiiirst(second)  "<<itr->second<<endl;
	map<string, int>::iterator t;
	t=mas.lower_bound("abc");
	cout << t->first << endl;
	cout << t->second << endl;
	pair<string,int> gip=move(pair<string, int>("geek", 10));
	pair<string, int>* hh = &gip;
	pair<string,int>* hq(&(pair<string, int>("ssss", 102)));
	cout << hh->first << endl;
	reverse_iterator<map<string, int>::iterator>h(t);
	cout<<(h.base())->first<<endl;
	cout << &h<<"\t"<<&t<<endl;
	vector<int>v1 = { 1,3,5 };
	vector<int>v2 = { 10 };
	back_insert_iterator <vector<int>>gopa(v2);
	copy(v1.begin(), v1.end(),gopa);
	for (auto el : v2) {
		cout << el << "\t";
	} cout << endl;
	shared_ptr<C>p1(new C);
	weak_ptr<C>p2(p1);
	cout <<&p2 << endl; 
	cout<<&p1<<endl;
	weak_ptr<int>s;
	cout<<s.expired()<<endl;
	cout<<s.lock()<<endl;
	allocator<int>ma;
	int* giga=std::allocator_traits<allocator<int>>::allocate(ma,4);
	std::allocator_traits<allocator<int>>::construct(ma, giga, 99);
	std::allocator_traits<allocator<int>>::destroy(ma, giga);
	std::allocator_traits<allocator<int>>::deallocate(ma, giga, 4);
	//iterator<random_access_iterator_tag,int>biba;
	//iterator_traits<iterator<random_access_iterator_tag, int>>::iterator_category;
	constexpr int bla=fib(10); cout << bla << endl;
	constexpr int y=20; constexpr double x=100.1;
	constexpr bool sameres=is_same<decltype(x), decltype(y)>::value;
	conditional<x == 5, int, double>::type yy;
	constexpr bool conres(conjunction<true_type, false_type>::value);
	constexpr bool disres(disjunction<false_type, true_type>::value);
		cout << disres << endl;
	constexpr bool negres(negation<false_type>::value);
	std::decay<int*>;
	int xx[2][4][5];
	int res = rank<decltype(xx)>::value; cout << res<<endl;
	tuple_<int, double, int> t1(12, 2.34, 89);
	tuple<int, double, int> t2(12, 2.34, 89);
	cout << t1.head_ << "\t" << t1.base.head_ <<"\t"<< t1.base.base.head_<<endl;
	cout<<is_class_<decltype(xx)>::value<<endl;
	int a = 0; int b = 10;
	int res1=(a++, --b);cout << res1 << endl;
	int n1 = 10; int& n2 = n1;
	reference_wrapper<int>zip(n2); cout<<is_same<decltype(n2), decltype(zip.get())>::value<<endl;
	POD pod{ 25,2.2,'s' };
	auto [g, z, z1] = pod;
	cout << z1;
	tuple driv(5, 22, "sds");
	auto [a_,b_,c_] = driv;
	cout << b_ << endl;
	int (*powerfunc)(double x)=&fruit; //-functionpointer-pointer to a func with param-s(double) and return type int
	cout << argv[0] << endl;
	cout << fruit << endl;
	cout << &fruit << endl;
	cout << powerfunc << endl;
	cout << &powerfunc << endl;
	cout << *powerfunc << endl; vector <int>sab_(10);
	vector<int>::iterator a__ = sab_.begin();
	vector<int>::iterator as__ = sab_.end();
	//std::sort(a__, as__);
	int alb[100];
	100[alb];// -  the same as *(alb+100)
	cout << gpntb<<endl;
	something(int());
	tr t_;
	tr* t__=&t_;
	int* vzlom=reinterpret_cast<int*>(t__);
	cout << *(vzlom+2)<<endl;
	cout << __cplusplus << endl;
	return 0;
}
//functor/functions(entity that supports operator()) -- predicates(functions/functors which return boolean value)
//namespace x{foo(){}} namespace z{foo()} - x::foo();z::foo();
/*#include <thread>-работа с потоками, "this_thread"::x-x=метод пространства имен this_thread--get_id(),sleep_for(chrono::milliseconds(z)),
#include <chrono>-работа современем-thread name(pointeronFunction,param1,param2);-object-detach()-обрывПотока if mainthread ended,join()-waiting of ending ofother thread
thread t(([&x](){x=Sum(2,5);});либо thread t(DoWork, ref(q));-"std::ref(x)"возвращение результата из thread, если функция/метод/параметр впотоке принимает ссылку на объект-
#include <mutex> -synchronisingthreads-mutex name;-lock(),unlock(),lock_guard<t>name();
recursive_mutex name;*/
/*"enum name{};"-enum PCstate {OFF, ON, SLEEP,PAIN=1000}; if(PCstate::ON){}; -перечисляемый набор констант
директивыПредпроцессора #define DEBUG-const, #define p 3.14- autoreplace
typedef std::vector<int> vector; -replace, new allias for existedtypes
#ifdef DEBUG OR #ifndef DEBUG-inverted-кодinsideworks if DEBUGwill defined-#else OR #elseif OR #if DEBUG>4- #endif
#pragma once -protectfromloopinclude-#pragma pack(1)-turnoff alignment(struct)-*/
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
STL контейнер #include<set> -на основе ,БИНАРНОГО древа-stores uniquevalue(key)- set<type> name; multiset<type> name;-value can be repeated, upper_bound(x),lower_bound(x), equal_range(x)-arrчиселот u_b до l_b -
STL контейнер #include<map> на осн БИНАРНОГО древа -stores uniquekey and value-sortingbased on key-map<t1,t2> name;-std::pair<t1,t2> name;- multimap<t1,t2> name;-key can be repeated- -addPair "insert(make_pair(t1,t2));","emplace(t1,t2);","insert(pair<t1,t2>(x1,x2))"
STL адаптеры-контейнеров -limitfunctional to adapter- #include<stack> "LastIN-FirstOut" #include<queue>-"FirstIN-FirstOut" -priority_queue<>n;-size(),push(),pop(),swap(),back(),emplace(),empty(),front()
STL algorithms -#include <algorithm>,#include<numeric> -count_if(first,last,predicate),find(F,L,value),find_if(F,L,Pred),find_if_not(F,L,P),copy(F,L,Destination),copy_if(F,L,D,Pred),
remove(F,L,value)-push non-appropr totheend,return Iterator-,remove_if(F,L,Pred),unique(F,L)-push non-unique totheend,return Iterator-,unique_copy(F,L,Dest)
max_element(F,L),min_element(F,L),accumulate(F,L,startValue),equal(F,L,F2,L2), for_each(F,L,whatDo), random_shuffle(F,L)
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
 //union{} - syntax,подобен классу- sharing local memory between different value, but in one moment contains only one data -newemerge #include <variant> variant<types...>n;
 /* ofstream for writing to a file, ifstream for reading from a file
 #include<fstream>-it works with files- ofstream xFile;- xFile.open("tuna.txt");-what file will be associated with that object-xFile.close();-для выгрузки памяти
 (fin.read((char*)& pnt, sizeof(Point)));-read/write from Point pnt,sizeof(x)
 ofstream xFile("beefjerky.txt"); if(xFile.is_open()){} -".is_open()"-check if object was associated with file correctly
 -ДоступныСостояния- fstream::in-read-,fstream::out-write-,fstream::app-appendData- 
-overload "<<"-ostream& operator<<(ostream&os, const Point& p) {os << p.x << " " << p.y << " " << p.z << endl;return os;}
-overload ">>""-istream& operator>>(istream& is, Point& pp) {is >> pp.x >> pp.y >> pp.z;return is;
} */
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
//#include <cstdarg> -func с переменным числом arguments - type Fname(...){}
//user_defined conversion function- operator convers_t(){}
//#include <cassert>-assert(any expr),static_assert(compiletime expr)-turnoff asserts in ReleaseConfig  #define NDEBUG
// keyword volatile - compiler won't optimize such value, because it's can be changed from the other thread
// c++ atributes [[nodiscard/noreturn/deprecated/maybe_unused/fallthrough]] -nodiscard-returnvalue should be used-
//Linux #include <getopt.h> - getopt(argc,argv,"short_opt") - getopt_long(argc,argv,const char* sth, const struct option* longsth, int*longindex)
//Linux #include <syslog.h> - openlog(char*name,int option,int facility)-syslog(int priority, char* text)-closelog()
//void* malloc(size_t size_inbytes), void free(void* ptr) -reserve and free memory for heap -thread safe(synchronisation)-