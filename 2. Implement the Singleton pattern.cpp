// 不好的解法一：只使用与单线程环境
class singleton1 {
public:
	static singleton1* getinstance() {
		return &m_instance;
	}
private:
	// 1. 构造函数私有 
	singleton1() {};
 
	// 2. 采用 c++11删除函数  拷贝函数、赋值运算符私有
	singleton1(singleton1 const&) = delete;
	singleton1& operator=(singleton1 const&) = delete;
	
	static singleton1 m_instance;    
};
 
singleton1 singleton1::m_instance; 


// 单线程懒汉模式
class Singleton
{
public:
	static Singleton* getInstance() {
		// 提高后续线程调用接口的效率
		if (_sin == nullptr) {       // 第一次为空，创建对象，第二次非空，直接返回，保证单例
			_sin = new Singleton;
		}
		return _sin;
	}
private:
	Singleton(){}       
	Singleton(const Singleton& s) = delete;

	static Singleton* _sin;        // 定义为指针，与对象不为同一类型，其为单独的指针类型
};

Singleton* Singleton::_sin = nullptr;

// 不好的解法二：虽然在多线程环境中能工作但效率不高
// 单线程懒汉模式
#include <mutex>  // 加锁头文件，互斥锁，所有的线程共用同一把锁，全局只有一把锁，用一把锁限制所有线程

class Singleton {
private:
    static mutex _mtx;	              // 全局只有一把锁，限制全部线程
public:
	static Singleton* getInstance() {
	    _mtx.lock();                  // 加锁不能在if内，没有意义，还是要创建对象
	    if (_sin == nullptr) {        // 第一次为空，创建对象，第二次非空，直接返回，保证单例
	        _sin = new Singleton;
	    }
	    _mtx.unlock();
	}
private:
	// 1. 构造函数私有化   2. 拷贝构造私有化（不必实现）   3. 赋值运算符无所谓私有化，因为其不创建新的对象
	Singleton(){}       
	Singleton(const Singleton& s) = delete;

	static Singleton* _sin;        // 定义为指针，与对象不为同一类型，其为单独的指针类型
};

Singleton* Singleton::_sin = nullptr;

// 可行的解法：加同步锁前后两次判断实例是否已存在
// 单线程懒汉模式
#include <mutex>  // 加锁头文件，互斥锁，所有的线程共用同一把锁，全局只有一把锁，用一把锁限制所有线程

class Singleton {
private:
    static mutex _mtx;	              // 全局只有一把锁，限制全部线程
public:
	static Singleton* getInstance() {
	    if (_sin == nullptr) {
	        _mtx.lock();                 // 加锁不能在if内，没有意义，还是要创建对象
	        if (_sin == nullptr) {       // 第一次为空，创建对象，第二次非空，直接返回，保证单例
				_sin = new Singleton;
	        }
	    	_mtx.unlock();
	    }
	    return _sin;
	}
private:
	// 1. 构造函数私有化   2. 拷贝构造私有化（不必实现）   3. 赋值运算符无所谓私有化，因为其不创建新的对象
	Singleton(){}       
	Singleton(const Singleton& s) = delete;

	static Singleton* _sin;        // 定义为指针，与对象不为同一类型，其为单独的指针类型
};

Singleton* Singleton::_sin = nullptr;

// 强烈推荐的解法一：利用静态构造函数
// 在 C# 有静态构造函数的写法，在此我也没学习过 C#，故不作讨论，可参见书本的 P34-强烈推荐的解法一：
// 利用静态构造函数中所讲。在此主要关注 强烈推荐的解法二：实现按需创建实例。


// 强烈推荐的解法二：内部类写法
Singleton* ps = Singleton::GetInstance();
delete ps;
ps = nullptr;


class Singleton {
public:
	static Singleton* getInstance() {
		if (_sin == nullptr) {
			_mtx.lock();                 
			if (_sin == nullptr) {       // 第一次为空，创建对象，第二次非空，直接返回，保证单例
				_sin = new Singleton;
			}
			_mtx.unlock();
		}
		return _sin;
	}
	
	class GC {     // 定义内部类，进行垃圾回收
	public:
		~GC() {
			if (_sin) {
				delete _sin;
				_sin = nullptr;
			}
		}
	};

private:
	
	Singleton(){}       
	Singleton(const Singleton& s) = delete;

	static Singleton* _sin;       
	static mutex _mtx;			 
	static GC _gc;
};

Singleton* Singleton::_sin = nullptr;
mutex Singleton::_mtx;
Singleton::GC Singleton::_gc; // 它是静态成员，其生命周期也是整个程序的生命周期，调用析构函数释放空间


​class Singleton {
public:
	static Singleton* getInstance() {
		if (_sin == nullptr) {
			_mtx.lock();                
			if (_sin == nullptr) {      
				_sin = new Singleton;
			}
			_mtx.unlock();
		}
		return _sin;
	}
	~Singleton() {    // 单例中析构函数产生递归效果
		if (_sin) {   // 之前所产生的对象不为当前类，不会重复递归调用析构函数
			delete _sin;
			_sin = nullptr;
		}
	}
	
