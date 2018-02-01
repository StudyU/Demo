#ifndef _PUBLIC_IVARTABLE_H
#define _PUBLIC_IVARTABLE_H

#include "Macros.h"
#include "IVarList.h"
//#include "SharePtr.h"

// 表接口

class IVar;

class IVarTable
{
public:
	virtual ~IVarTable() = 0;

	// 获得表项数量
	virtual size_t GetCount() const = 0;
	// 获得键名列表
	virtual void GetKeyList(IVarList& result) const = 0;
	// 获得键值
	virtual IVar* GetValue(const char* key) const = 0;
	// 键值是否存在
	virtual bool Exists(const char* key) const = 0;
	// 添加键
	virtual IVar* Add(const char* key, const IVar& value) = 0;
	// 删除键
	virtual bool Remove(const char* key) = 0;
	// 清空
	virtual void Clear() = 0;
	// 设置键值（不存在则添加）
	virtual void Assign(const char* key, const IVar& value) = 0;
};

inline IVarTable::~IVarTable() {}

/*
class IVar;

typedef TSharePtr<IVar> IVarPointer;

class IVarTable
{
public:
	virtual ~IVarTable() = 0;

	// 获得表项数量
	virtual size_t GetCount() const = 0;
	// 获得键名列表
	virtual size_t GetKeyList(IVarList& result) const = 0;
	// 获得键值
	virtual const IVarPointer* GetVarPointer(const char* key) const = 0;
	// 键值是否存在
	virtual bool Exists(const char* key) const = 0;
	// 添加键
	virtual const IVarPointer* Add(const char* key, 
		const IVarPointer& vp) = 0;
	// 删除键
	virtual bool Remove(const char* key) = 0;
	// 清空
	virtual void Clear() = 0;
};

inline IVarTable::~IVarTable() {}
*/

#endif // _IVARTABLE_H

