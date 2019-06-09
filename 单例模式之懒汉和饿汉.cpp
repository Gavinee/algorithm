///Design Patterns : 单例模式
///Function :		 饿汉模式
///Author :			 Qiufeng

#include <iostream>

class Singleton {
public:
	static Singleton* GetInstance() 
	{
		return singleton_;
	}

	static void DestroyInstance()
	{
		if (singleton_ != NULL)
		{
			delete singleton_;
		}
	}

private:
	//防止外部构造
	Singleton() = default;

	//防止拷贝和复制
	Singleton& operator =(const Singleton&) = delete;
	Singleton(const Singleton& singleton2) = delete;

public:
	static Singleton* singleton_;
};

Singleton* Singleton::singleton_ = new Singleton;

int main(void)
{
	Singleton* s1 = Singleton::GetInstance();
	std::cout << s1 << std::endl;
	
	Singleton* s2 = Singleton::GetInstance();
	std::cout << s2 << std::endl;

	//Singleton->DestroyInstance();
	system("pause");

	return 0;
}

/*
*		输出:
*			  04B6978
*			  04B6978
*/



///Design Patterns : 单例模式
///Function :		 懒汉模式
///Author :			 Qiufeng

#include <iostream>
#include <mutex>

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (instance_ == nullptr)
		{
			std::lock_guard<std::mutex> lock(mutex_);
			if (instance_ == nullptr)
			{
				instance_ = new Singleton;
			}
		}
		return instance_;
	}

	~Singleton() = default;

	//释放资源
	void Destroy()
	{
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	void PrintAddress() const
	{
		std::cout << this << std::endl;
	}

private:
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

private:
	//例子
	static Singleton* instance_;
	//互斥锁
	static std::mutex mutex_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

int main(void)
{
	Singleton* s1 = Singleton::GetInstance();
	s1->PrintAddress();

	Singleton* s2 = Singleton::GetInstance();
	s2->PrintAddress();

	system("pause");
	return 0;
}

/*
*		输出:
*			0149F308
*			0149F308
*/


///Design Patterns : 单例模式
///Function :		 优化懒汉模式
///Author :			 Qiufeng

// 上述程序需要手动调用Destroy()来释放该单例管理的资源。
// 如果不去手动释放管理的资源(例如加载的文件句柄等),
// 虽然程序结束会释放这个单例对象的内存
// 但是没有调用其析构函数去关闭这些管理的资源句柄。
// 解决办法就是将该管理的对象用智能指针管理

#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		if (!instance_)
		{
			std::lock_guard<std::mutex> lock(mutex_);
			if (!instance_)
			{
				//直接调用:智能指针本身有属性，所以直接调用中有属性
				//间接调用:而间接调用是指针类型所指的对象
				instance_.reset(new Singleton);
			}
		}
		return *instance_;
	}

	~Singleton() = default;

	void PrintAddress()const
	{
		std::cout << this << std::endl;
	}

private:
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

private:

	static std::unique_ptr<Singleton> Singleton::instance_;
	static std::mutex mutex_;
};

std::unique_ptr<Singleton> Singleton::instance_;
std::mutex Singleton::mutex_;

int main(void)
{
	Singleton& s1 = Singleton::GetInstance();
	s1.PrintAddress();
	Singleton& s2 = Singleton::GetInstance();
	s2.PrintAddress();

	return 0;
}

/*
*		输出:
*			0149F308
*			0149F308
*/



///Design Patterns : 单例模式
///Function :		 std::call_once懒汉模式
///Author :			 Qiufeng

#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static std::once_flag s_flag;
		std::call_once(s_flag, [&]()
		{instance_.reset(new Singleton); 
		});
		return *instance_;
	}

	~Singleton() = default;

	void PrintAddress()const
	{
		std::cout << this << std::endl;
	}

private:
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	static std::unique_ptr<Singleton> instance_;
};

//unique_ptr 不共享指针
std::unique_ptr<Singleton>Singleton::instance_;

int main(void)
{
 	Singleton& s1 = Singleton::GetInstance();
	s1.PrintAddress();
	
	Singleton& s2 = Singleton::GetInstance();
	s2.PrintAddress();

	return 0;
}

/*
*		输出:
*			0149F308
*			0149F308
*/


///Design Patterns : 单例模式
///Function :		 使用局部静态变量实现懒汉模式
///Author :			 Qiufeng

#include <iostream>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton instance;
		return instance;
	}

	~Singleton() = default;

private:
	Singleton() = default;

	Singleton(const Singleton&) = delete;

	Singleton& operator = (const Singleton&) = delete;
};

int main(void)
{
	Singleton& s1 = Singleton::GetInstance();
	std::cout << &s1 << std::endl;

	Singleton& s2 = Singleton::GetInstance();
	std::cout << &s2 << std::endl;

	return 0;
}


/*
*		输出:
*			0149F308
*			0149F308
*/
