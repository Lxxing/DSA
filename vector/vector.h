


namespace LX
{
typedef int Rank;
#define DEFAULT_CAPACITY 5;

templete <typename T>
class vector
{

public:
	vector(int cap = DEFAULT_CAPACITY);
	~vector();

	Rank size() const;
	bool empty() const;
	T& get(Rank r);
	
	
		
private:
	T * _data;
	int _size;
	int _capacity;

};

}


