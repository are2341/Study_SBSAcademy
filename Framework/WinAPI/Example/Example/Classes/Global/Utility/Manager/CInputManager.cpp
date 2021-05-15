#include "CInputManager.h"
#include "../Base/CWndApp.h"

CInputManager::CInputManager(void) {
	ZeroMemory(m_anKeyStates, sizeof(m_anKeyStates));
	ZeroMemory(m_anPrevKeyStates, sizeof(m_anPrevKeyStates));

	ZeroMemory(&m_stMouseState, sizeof(m_stMouseState));
	ZeroMemory(&m_stPrevMouseState, sizeof(m_stPrevMouseState));
}

CInputManager::~CInputManager(void) {
	SAFE_UNACQUIRE(m_pKeyboardDevice);
	SAFE_UNACQUIRE(m_pMouseDevice);

	SAFE_RELEASE(m_pDInput);
}

void CInputManager::Init(void) {
	m_pDInput = this->CreateDInput();
	m_pKeyboardDevice = this->CreateKeyboardDevice();
	m_pMouseDevice = this->CreateMouseDevice();
}

void CInputManager::Update(float a_fDeltaTime) {
	CopyMemory(m_anPrevKeyStates, m_anKeyStates, sizeof(m_anKeyStates));
	CopyMemory(&m_stPrevMouseState, &m_stMouseState, sizeof(m_stMouseState));

	m_pKeyboardDevice->GetDeviceState(sizeof(m_anKeyStates), (LPVOID)m_anKeyStates);
	m_pMouseDevice->GetDeviceState(sizeof(m_stMouseState), (LPVOID)&m_stMouseState);
}

bool CInputManager::IsKeyDown(BYTE a_nKeyCode) const {
	return m_anKeyStates[a_nKeyCode] & 0x80;
}

bool CInputManager::IsKeyPress(BYTE a_nKeyCode) const {
	return this->IsKeyDown(a_nKeyCode) && !(m_anPrevKeyStates[a_nKeyCode] & 0x80);
}

bool CInputManager::IsKeyRelease(BYTE a_nKeyCode) const {
	return !this->IsKeyDown(a_nKeyCode) && (m_anPrevKeyStates[a_nKeyCode] & 0x80);
}

bool CInputManager::IsMouseBtnDown(EMouseBtn a_eMouseBtn) const {
	return m_stMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80;
}

bool CInputManager::IsMouseBtnPress(EMouseBtn a_eMouseBtn) const {
	return this->IsMouseBtnDown(a_eMouseBtn) && !(m_stPrevMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80);
}

bool CInputManager::IsMouseBtnRelease(EMouseBtn a_eMouseBtn) const {
	return !this->IsMouseBtnDown(a_eMouseBtn) && (m_stPrevMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80);
}

int CInputManager::GetMouseWheel(void) const {
	return m_stMouseState.lZ;
}

POINT CInputManager::GetMousePos(void) const {
	POINT stMousePos;
	GetCursorPos(&stMousePos);
	ScreenToClient(GET_WND_HANDLE(), &stMousePos);

	return stMousePos;
}

IDirectInput8 * CInputManager::CreateDInput(void) {
	IDirectInput8 *pDInput = nullptr;
	assert(SUCCEEDED(DirectInput8Create(GET_INST_HANDLE(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID *)&pDInput, NULL)));

	return pDInput;
}

IDirectInputDevice8 * CInputManager::CreateKeyboardDevice(void) {
	IDirectInputDevice8 *pKeyboardDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysKeyboard, &pKeyboardDevice, NULL)));

	pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	pKeyboardDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	pKeyboardDevice->Acquire();

	return pKeyboardDevice;
}

IDirectInputDevice8 * CInputManager::CreateMouseDevice(void) {
	IDirectInputDevice8 *pMouseDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL)));

	pMouseDevice->SetDataFormat(&c_dfDIMouse);
	pMouseDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	pMouseDevice->Acquire();

	return pMouseDevice;
}
