
#include<windows.h>
#include<vector>
#include <iostream>
#include<iterator>

class MapGraphics
{
protected:
    BITMAP m_BMP;   // �g�p����G
    int m_width;          // �G�̕�
    int m_height;         // �G�̍���
    int m_MapCode;     // �G�̃R�[�h

public:
    virtual void CreateMap() = 0;
    MapGraphics* Clone() {};    // �����֐�

};

template<class T>
class My_Allocator {

    using value_type = T;

    My_Allocator() {}

    // �ʂȗv�f�^�̃A���P�[�^���󂯎��R���X�g���N�^
    template <class U>
    My_Allocator(const My_Allocator<U>&) {}


    // �������m��
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
    using difference_type =  std::ptrdiff_t;//�����t�������^
    using value_type = T;
   // using pointer = Allocator::pointer;
   // using const_pointer = ;
   // using reverse_iterator = ;
   // using const_reverse_iterator = ;



    MapGraphics* map;


public:

    void  assign();	//�R���e�i�̍đ��
    void  push_back();  //	�����֗v�f�ǉ�
    void  emplace_back(); //	�����֒��ڍ\�z	C++11
    void  pop_back(); //	��������v�f�폜
    void  insert();	//�v�f�̑}��
    void  emplace();	//�v�f�̒��ڍ\�z�ɂ��}��	C++11
    void  erase(); //�v�f�̍폜
    void  swap();	//�R���e�i�̌���
    void  clear();	//�S�v�f�폜

    void front();  //�擪�v�f�ւ̎Q�Ƃ��擾����
    void back(); //�����v�f�ւ̎Q�Ƃ��擾����


    void size();	//�v�f�����擾����
    void max_size();	//�i�[�\�ȍő�̗v�f�����擾����
    void resize();	//�v�f����ύX����
    void capacity();	//���������Ċm�ۂ����Ɋi�[�ł���ő�̗v�f�����擾����
    void empty();	//�R���e�i���󂩂ǂ����𔻒肷��
    void reserve();	//capacity��ύX����
    void shrink_to_fit();	//capacity��size�܂ŏk������


protected:

    void begin();	//�擪�̗v�f���w���C�e���[�^���擾����
    void end();	//�����̎����w���C�e���[�^���擾����
    void cbegin();	//�擪�̗v�f���w���ǂݎ���p�C�e���[�^���擾����	C++11
    void cend();	//�����̎����w���ǂݎ���p�C�e���[�^���擾����	C++11
    void rbegin();	//�������w���t�C�e���[�^���擾����
    void rend();	//�擪�̑O���w���t�C�e���[�^���擾����
    void crbegin();	//�������w���ǂݎ���p�t�C�e���[�^���擾����	C++11
    void crend();


    auto operator==(My_Map_vector) {};	//���l��r
    auto operator!=(My_Map_vector) {};	//�񓙒l��r
    auto operator<(My_Map_vector) {};	//���ӂ��E�ӂ�菬�������̔�����s��
    auto operator<=(My_Map_vector) {};	//���ӂ��E�ӈȉ����̔�����s��
    auto operator>(My_Map_vector) {};	//���ӂ��E�ӂ��傫�����̔�����s��
    auto operator>=(My_Map_vector) {};	//���ӂ��E�ӈȏォ�̔�����s��

};


class MapManager
{
protected:
  
    std::vector<MapGraphics*> m_MapPartVect;
 

public:
    MapGraphics* GetPart(int map_id) {

        return  m_MapPartVect[map_id]->Clone();

    };   // �}�b�v�̃p�[�c���
    void AddPart(MapGraphics clone()) {};
};


class MapMountain : public MapGraphics
{
public:
    virtual void CreateMap() {
        // �R�̊G��ǂݍ��ݕ��⍂�����i�[����
    }
};

class MapRiver : public MapGraphics
{
public:
    virtual void CreateMap() {
        // ��̊G��ǂݍ��ݕ��⍂�����i�[����
    }
};

//�����͈�񂾂��p�[�c�̃R�s�[�͊֐��ł��









int main() {

    My_Map_vector<int, CMyClassIterator,My_Allocator<int>> m;


}