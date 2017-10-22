#pragma once

class CObject;
class CFsm;

class CState
{
public:
	unsigned int m_id;
	CFsm* m_pFSM;

	virtual void onEnter();
	virtual unsigned int update(void* pObject);
	virtual void onExit();

	CState();
	CState(unsigned int id) : m_id(id), m_pFSM(nullptr) {}
	virtual ~CState();

	void SetFSM(CFsm* pFSM) {
		m_pFSM = pFSM;
	}
};

