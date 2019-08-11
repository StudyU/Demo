#pragma once
#include <map>
#include <type_traits>

#define ADD_GM_METHOD(func_name) GMethodCreator::Add(#func_name, RTTIFuncTypeOf(func_name))
#define ADD_GM_METHOD_OBJ(func_name,obj) GMethodCreator::Add(#func_name, RTTIFuncTypeOf(obj,&func_name))
#define REMOVE_GM_METHOD_OBJ(obj) GMethodCreator::RemoveByObj(obj)

////////////////////////方法包装基础类//////////////////////////
class MethodType
{
public:
	MethodType() :m_bIsStatic(false), m_pObj(nullptr) {}
	//virtual void Invoke(_KERNEL* pKernel, const IVarList& args, IVarList& res) = 0;
	bool IsStatic() { return m_bIsStatic; }
	void* GetObj() { return m_pObj; }
protected:
	bool m_bIsStatic;						// 是否类里面的静态成员函数
	void* m_pObj;							// 成员对象
};


template<class __RT, class __C, class ...Args>
class RTTIFuncType : public MethodType
{
public:
	typedef __RT(__C::*fptr)(Args...);
	fptr f;
	__C* obj;

	RTTIFuncType(__C* obj, fptr f)
	{
		this->f = f;
		this->m_pObj = (void*)obj;
	}

	static void Invoke()
	{
		std::invoke(f, obj, Args...);
	}
	//virtual void Invoke(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	InnerInvoke<__RT>(pKernel, args, res);
	//}

private:

	//template<class ___RT>
	//void InnerInvoke(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	int nIndex = 0;
	//	res.AddString(TypeToString((((__C*)m_pObj)->*f)(ARGS1(pKernel, args, nIndex))).c_str());
	//}

	//template<>
	//void InnerInvoke<void>(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	int nIndex = 0;
	//	(((__C*)m_pObj)->*f)(ARGS1(pKernel, args, nIndex));
	//	res.AddString("void");
	//}
};


template<class __RT, class ...Args>
class RTTIFuncType_s : public MethodType
{
public:
	typedef __RT(*fptr)(Args...);
	fptr f;

	RTTIFuncType_s(fptr f)
	{
		this->f = f;
		m_bIsStatic = true;
	}

	//virtual void Invoke(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	InnerInvoke<__RT>(pKernel, args, res);
	//}

	static void Invoke()
	{
		std::invoke(f, Args...);
	}

private:

	//template<class ___RT>
	//void InnerInvoke(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	int nIndex = 0;
	//	res.AddString(TypeToString(((*f)(ARGS1(pKernel, args, nIndex)))).c_str());
	//}

	//template<>
	//void InnerInvoke<void>(_KERNEL* pKernel, const IVarList& args, IVarList& res) {
	//	int nIndex = 0;
	//	(*f)(ARGS1(pKernel, args, nIndex));
	//	res.AddString("void");
	//}

};

// 类成员函数
template<class __RT, class __C, class ...Args>
inline MethodType* RTTIFuncTypeOf(__C* obj, __RT(__C::*f)(Args...)) {
	return new RTTIFuncType<__RT, __C, Args...>(obj, f);
}

// 静态或全局函数
template<class __RT, class ...Args>
inline MethodType* RTTIFuncTypeOf(__RT(*f)(Args...)) {
	return new RTTIFuncType_s<__RT, Args...>(f);
}
class GMethodCreator
{
private:
	typedef std::map<std::string, MethodType*> MapMethod;
	static MapMethod m_mapMethod;
public:
	template<typename... Args>
	static bool Invoke(const char* szFuncName, const Args& ...)
	{
		if (szFuncName == nullptr)
		{
			return false;
		}

		MapMethod::iterator iter = m_mapMethod.find(szFuncName);
		if (iter == m_mapMethod.end())
		{
			return false;
		}

		MethodType* pMethod = iter->second;
		if (pMethod == NULL)
		{
			return false;
		}

		pMethod->Invoke();
		return true;
	}

	static bool Add(const char* szName, MethodType* pMethod)
	{
		if (szName == nullptr)
		{
			return false;
		}

		if (pMethod == NULL)
		{
			return false;
		}

		MapMethod::iterator iter = m_mapMethod.find(szName);
		if (iter != m_mapMethod.end())
		{
			return false;
		}

		m_mapMethod.insert(std::make_pair(szName, pMethod));

		return true;
	}

	static bool Remove(const char* szName)
	{
		if (szName == nullptr)
		{
			return false;
		}

		MapMethod::iterator iter = m_mapMethod.find(szName);
		if (iter == m_mapMethod.end())
		{
			return false;
		}

		if (iter->second != nullptr)
		{
			delete(iter->second);
			iter->second = nullptr;
		}

		m_mapMethod.erase(iter);

		return true;
	}

	static bool RemoveByObj(void* pObj)
	{
		if (pObj == NULL)
		{
			return false;
		}

		for (MapMethod::iterator iter = m_mapMethod.begin(); iter != m_mapMethod.end();)
		{
			MethodType* pMethod = iter->second;
			if (pMethod != NULL && !pMethod->IsStatic() && pMethod->GetObj() == pObj)
			{
				if (iter->second != nullptr)
				{
					delete(iter->second);
					iter->second = nullptr;
				}

				iter = m_mapMethod.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		return true;
	}

	static bool RemoveAll()
	{
		for (MapMethod::iterator iter = m_mapMethod.begin(); iter != m_mapMethod.end();)
		{
			if (iter->second != nullptr)
			{
				delete(iter->second);
				iter->second = nullptr;
			}
		}

		m_mapMethod.clear();

		return true;
	}
};
