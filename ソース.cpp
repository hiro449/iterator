
#include<windows.h>
#include<vector>
#include <iostream>
#include<iterator>

class MapGraphics
{
protected:
    BITMAP m_BMP;   // 使用する絵
    int m_width;          // 絵の幅
    int m_height;         // 絵の高さ
    int m_MapCode;     // 絵のコード

public:
    virtual void CreateMap() = 0;
    MapGraphics* Clone() {};    // 複製関数

};

template<class T>
class My_Allocator {

    using value_type = T;

    My_Allocator() {}

    // 別な要素型のアロケータを受け取るコンストラクタ
    template <class U>
    My_Allocator(const My_Allocator<U>&) {}


    // メモリ確保
    T* allocate(std::size_t n)
    {
        return reinterpret_cast<T*>(std::malloc(sizeof(T) * n));
    }

    void deallocate(T* p, std::size_t n)
    {
        static_cast<void>(n);
        std::free(p);
    }


   
};

template <class T, class U>
bool operator==(const My_Allocator<T>&, const My_Allocator<U>&)
{
    return true;
}

template <class T, class U>
bool operator!=(const My_Allocator<T>&, const My_Allocator<U>&)
{
    return false;
}


class CMyClassIterator;


class CMyClassIterator : public std::iterator<std::forward_iterator_tag, int>

{
    friend class CMyClass;
private:

    size_t m_index;
    CMyClass* m_myClass;

private:

    CMyClassIterator();
    CMyClassIterator(CMyClass* myClass, int index);
  

public:
    CMyClassIterator(const CMyClassIterator& iterator);
  
public:

    CMyClassIterator& operator++();
    CMyClassIterator operator++(int);
    int& operator*();

    bool operator==(const CMyClassIterator& iterator);
    bool operator!=(const CMyClassIterator& iterator);

};


class CMyClass
{

    friend class CMyClassIterator;

public:

    typedef CMyClassIterator iterator;

    CMyClass::iterator begin();

    CMyClass::iterator end();

private:

    int m_serial;

public:

    CMyClass();

    CMyClass(const CMyClass& myClass);

    int serial() const;

};

template < typename T, typename Iterator = CMyClassIterator ,typename Allocator = My_Allocator<T> >
class My_Map_vector {

private:

    using reference = T&;
    using const_reference = const T&;
    using const_iterator = const Iterator;
    using size_type = std::size_t;
    using difference_type =  std::ptrdiff_t;//符号付き整数型
    using value_type = T;
   // using pointer = Allocator::pointer;
   // using const_pointer = ;
   // using reverse_iterator = ;
   // using const_reverse_iterator = ;



    MapGraphics* map;


public:

    void  assign();	//コンテナの再代入
    void  push_back();  //	末尾へ要素追加
    void  emplace_back(); //	末尾へ直接構築	C++11
    void  pop_back(); //	末尾から要素削除
    void  insert();	//要素の挿入
    void  emplace();	//要素の直接構築による挿入	C++11
    void  erase(); //要素の削除
    void  swap();	//コンテナの交換
    void  clear();	//全要素削除

    void front();  //先頭要素への参照を取得する
    void back(); //末尾要素への参照を取得する


    void size();	//要素数を取得する
    void max_size();	//格納可能な最大の要素数を取得する
    void resize();	//要素数を変更する
    void capacity();	//メモリを再確保せずに格納できる最大の要素数を取得する
    void empty();	//コンテナが空かどうかを判定する
    void reserve();	//capacityを変更する
    void shrink_to_fit();	//capacityをsizeまで縮小する


protected:

    void begin();	//先頭の要素を指すイテレータを取得する
    void end();	//末尾の次を指すイテレータを取得する
    void cbegin();	//先頭の要素を指す読み取り専用イテレータを取得する	C++11
    void cend();	//末尾の次を指す読み取り専用イテレータを取得する	C++11
    void rbegin();	//末尾を指す逆イテレータを取得する
    void rend();	//先頭の前を指す逆イテレータを取得する
    void crbegin();	//末尾を指す読み取り専用逆イテレータを取得する	C++11
    void crend();


    auto operator==(My_Map_vector) {};	//等値比較
    auto operator!=(My_Map_vector) {};	//非等値比較
    auto operator<(My_Map_vector) {};	//左辺が右辺より小さいかの判定を行う
    auto operator<=(My_Map_vector) {};	//左辺が右辺以下かの判定を行う
    auto operator>(My_Map_vector) {};	//左辺が右辺より大きいかの判定を行う
    auto operator>=(My_Map_vector) {};	//左辺が右辺以上かの判定を行う

};


class MapManager
{
protected:
  
    std::vector<MapGraphics*> m_MapPartVect;
 

public:
    MapGraphics* GetPart(int map_id) {

        return  m_MapPartVect[map_id]->Clone();

    };   // マップのパーツを提供
    void AddPart(MapGraphics clone()) {};
};


class MapMountain : public MapGraphics
{
public:
    virtual void CreateMap() {
        // 山の絵を読み込み幅や高さを格納する
    }
};

class MapRiver : public MapGraphics
{
public:
    virtual void CreateMap() {
        // 川の絵を読み込み幅や高さを格納する
    }
};

//生成は一回だがパーツのコピーは関数でやる









int main() {

    My_Map_vector<int, CMyClassIterator,My_Allocator<int>> m;


}