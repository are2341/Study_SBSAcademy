#include "CTimeManager.h"

CTimeManager::CTimeManager(void) {
	// Do Nothing
}

CTimeManager::~CTimeManager(void) {
	// Do Nothing
}

void CTimeManager::Init(void) {
	m_oPrevTime = std::chrono::system_clock::now();
	m_oStartTime = std::chrono::system_clock::now();
}

void CTimeManager::Update(void) {
	auto oCurTime = std::chrono::system_clock::now();

	m_fDeltaTime = std::chrono::duration<float>(oCurTime - m_oPrevTime).count();
	m_fRunningTime = std::chrono::duration<float>(oCurTime - m_oStartTime).count();

	m_oPrevTime = oCurTime;
}
