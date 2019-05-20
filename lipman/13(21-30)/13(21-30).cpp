#include <string>
#include <vector>
#include <iostream>

void N21()
{
	//ѕоскольку синтезированна€ верси€ отвечает всем требовани€м дл€ этого случа€, нет необходимости определ€ть пользовательские элементы управлени€ верси€ми.
}

void N22(){}
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
	HasPtr& operator=(const HasPtr &hp) {
		auto new_p = new std::string(*hp.ps);
		delete ps;
		ps = new_p;
		i = hp.i;
		return *this;
	}
	~HasPtr() {
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

void N24()
{
	// ≈сли бы hasptr не определил деструктор, произошла бы утечка пам€ти, созданный компил€тором деструктор не управл€ет динамической пам€тью.
	// ≈сли HasPtr не определить конструктор копировани€, мы получим копировани€ указател€ и обычную проблему с разделением динамической памм€ти
}

void N25()
{
	//  онструктор копировани€ и оператор присваивани€ копии должны динамически выдел€ть пам€ть самосто€тельно
	// динамическа€ пам€ть очиститс€, когда будет удален умный указатель
}

void N26()
{
	using std::vector; using std::string;

	class ConstStrBlobPtr;

	class StrBlob {
	public:
		using size_type = vector<string>::size_type;
		friend class ConstStrBlobPtr;

		ConstStrBlobPtr begin() const;
		ConstStrBlobPtr end() const;

		StrBlob() :data(std::make_shared<vector<string>>()) { }
		StrBlob(std::initializer_list<string> il) :data(std::make_shared<vector<string>>(il)) { }

		// copy constructor
		StrBlob(const StrBlob& sb) : data(std::make_shared<vector<string>>(*sb.data)) { }
		// copyassignment operators
		StrBlob& operator=(const StrBlob& sb);

		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }

		void push_back(const string &t) { data->push_back(t); }
		void pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		string& front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		string& back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		const string& front() const {
			check(0, "front on empty StrBlob");
			return data->front();
		}
		const string& back() const {
			check(0, "back on empty StrBlob");
			return data->back();
		}

	private:
		void check(size_type i, const string &msg) const {
			if (i >= data->size()) throw std::out_of_range(msg);
		}

	private:
		std::shared_ptr<vector<string>> data;
	};

	class ConstStrBlobPtr {
	public:
		ConstStrBlobPtr() :curr(0) { }
		ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { } // should add const
		bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
		const string& deref() const { // return value should add const
			auto p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		ConstStrBlobPtr& incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

	private:
		std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
			auto ret = wptr.lock();
			if (!ret) throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size()) throw std::out_of_range(msg);
			return ret;
		}
		std::weak_ptr<vector<string>> wptr;
		size_t curr;
	};
}

void N27()
{
	class HasPtr {
	public:
		HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) { }
		HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
		HasPtr& operator=(const HasPtr &rhs) {
			++*rhs.use;
			if (--*use == 0) {
				delete ps;
				delete use;
			}
			ps = rhs.ps;
			i = rhs.i;
			use = rhs.use;
			return *this;
		}
		~HasPtr() {
			if (--*use == 0) {
				delete ps;
				delete use;
			}
		}
	private:
		std::string *ps;
		int i;
		size_t *use;
	};
}

void N28()
{
	using std::string;

	class TreeNode {
	public:
		TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
		TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
		TreeNode& operator=(const TreeNode &rhs)
		{
			++*rhs.count;
			if (--*count == 0) {
				delete left;
				delete right;
				delete count;
			}
			value = rhs.value;
			left = rhs.left;
			right = rhs.right;
			count = rhs.count;
			return *this;
		}
		~TreeNode() {
			if (--*count == 0) {
				delete left;
				delete right;
				delete count;
			}
		}

	private:
		std::string value;
		int         *count;
		TreeNode    *left;
		TreeNode    *right;
	};

	class BinStrTree {
	public:
		BinStrTree() : root(new TreeNode()) { }
		BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) { }
		BinStrTree& operator=(const BinStrTree &bst)
		{
			TreeNode *new_root = new TreeNode(*bst.root);
			delete root;
			root = new_root;
			return *this;
		}
		~BinStrTree() { delete root; }

	private:
		TreeNode *root;
	};
}

void N29()
{
	//swap(lhs.ps, rhs.ps); вызывает: swap(std::string*, std::string*), а swap(lhs.i, rhs.i); вызывает : swap(int, int). 
	//ќни оба не могут вызвать swap(HasPtr&, HasPtr&). 
	//“аким образом, вызовы не вызывают цикл рекурсии.
}

void N30()
{
	class HasPtr {
	public:
	    friend void swap(HasPtr&, HasPtr&);
	    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
	    HasPtr& operator=(const HasPtr &hp) {
	        auto new_p = new std::string(*hp.ps);
	        delete ps;
	        ps = new_p;
	        i = hp.i;
	        return *this;
	    }
	    ~HasPtr() {
	        delete ps;
	    } 
	    
	    void show() { std::cout << *ps << std::endl; }
	private:
	    std::string *ps;
	    int i;
	};

	void swap(HasPtr& lhs, HasPtr& rhs);
	{
	    using std::swap;
	    swap(lhs.ps, rhs.ps);
	    swap(lhs.i, rhs.i);
	    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
	}
}