#pragma once

//#include <regex>
#include <string>
#include <vector>
#include <map>
#include <deque>

namespace std { typedef basic_string<TCHAR> tstring; }
namespace std { typedef basic_regex<TCHAR> tregex; }
namespace std { typedef match_results<tstring::const_iterator> tmatch; }

using namespace std::tr1;
using std::tmatch;
using std::tregex;
using std::tstring;
using std::map;
using std::vector;
using std::deque;


class ksfinfo;
template<class T> class Do
{
private:
	enum {SIZE=50};
public:
	Do()
	{
		index = -1;
		/*datalist.reserve(SIZE+1);*/
	}
	~Do()
	{
		//datalist.erase(datalist.begin(), datalist.end());
	}
	void saveHistory(const T& data)
	{
		/*datalist.push_back(data);
		index++;
		if(index > SIZE) // ���� ����
		{
			datalist.erase(datalist.begin());
			index--;
		}*/
	}
	T* unDo()
	{
		return index>0 ? &datalist[--index] : 0;
	}
	T* reDo()
	{
		if(datalist.size()-1 > index)
			return &datalist[++index];
		else
			return 0;		
	}
private:
	size_t index;
	std::vector<T> datalist;
};


class ksfinfo
{
private:
	struct StepData
	{
		vector<tstring> m_StepInfo;
		map<int, vector<tstring> > m_ChangeOfSpeed;
	}stepdata;

	struct RationalNumber
	{
		unsigned __int64 numerator;
		unsigned __int64 denominator;
	};

	struct TimeTable
	{
		map<int, vector<RationalNumber> > rationalnumbers;   // ���ڿ� �и�
		vector<double> result;
	}timetable;


	template <typename T> T getGCD(T u, T v);
	bool getTick(int index, int& t);
	bool getBpm(int index, double& b);
	void getDelay(int index, double b, int t, TimeTable& tt);
	template<class T> void swap(T& a, T& b);
	void getFromRegExp(tstring& dest, const std::tstring& str, tmatch& results, const tstring& exp);
	void getFromRegExp(int& dest, const std::tstring& str, tmatch& results, const tstring& exp);
	
public:
	Do<StepData> unredo;
public:
	tstring m_Title;
	tstring m_Player; // ��������
	tstring m_BPM1;
	int m_StartTime1;
	int m_TickCount; //1,2,3,4,5,6,7,8	
	tstring m_IntroFile; // ��������
	tstring m_SongFile; // ��������
	tstring m_DiscFile; // ��������
	tstring m_TitleFile; // ��������
	int m_Difficulty; // ��������
	tstring m_BPM2; // ��������
	tstring m_BPM3; // ��������
	int m_BunKi1; // ��������
	int m_BunKi2; // ��������
	int m_StartTime2; // ��������
	int m_StartTime3; // ��������

	const vector<tstring>& getStepInfo() {return stepdata.m_StepInfo;}
	const map<int, vector<tstring> >& getChangeOfSpeed() {return stepdata.m_ChangeOfSpeed;}
	const StepData& getStepData(){return stepdata;}
//	const vector<tstring>& getStepInfo() const{return m_StepInfo;}

	
	void IncCosFrom(int endsel);

public:
	ksfinfo();
	~ksfinfo();
//	int GetEnd(){return m_EndSelect;}
	BOOL LoadKSF(const TCHAR* path);
	BOOL SaveKSF(const TCHAR* path);
	void SetStep(bool doublemode, int position, int beginsel, int endsel);
	void Rotation(int player, int rotation, int s, int e);
	void Insert(int e, int size);
	void Pushback(int size);
	void Remove(int bs, int es);
	int InputTextInfo(const TCHAR* data, int e);
	void ChangeCos(int steppos, tstring str);
	void setStepData(const StepData* sd);
	void setSpace(int rangeS, int rangeE, bool Double, unsigned int spacevalue);
	void createTable();
	int timeToIndex(int t);
	int indexToTime(int in);
};














	//���ο� �ٹ����� �����ϴ� ���ӹ��
/*#TICKCOUNT: ����; (�Ǵ� |T����|) 
	��� �κ��� #TICKCOUNT ���� �ٲ۴�. 
#BPM: �Ǽ�; (�Ǵ� |B�Ǽ�|) 
		������ ��Ÿ����, �ش� ��ġ���� BPM ���� �����Ѵ�. 
#DELAY: ����; (�Ǵ� |D����|) 
		�ش� ��ġ���� ������Ʈ�� �ö���� ���� ������ �ð�(1/1000�� ����)��ŭ �ߴ��Ѵ�. 
#DELAYBEAT: ����; (�Ǵ� |E����|) 
		�ش� ��ġ���� ������Ʈ�� �ö���� ���� ������ �ð�(1���� ����)��ŭ �ߴ��Ѵ�. 
	*/