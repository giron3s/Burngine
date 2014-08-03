//////////////////////////////////////////////////////////////////////////////
//
// Burngine is distributed under the GNU GPL v2 License
// ====================================================
//
//    Copyright (C) 2014 Dominik David (frischer-hering@gmx.de)
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//////////////////////////////////////////////////////////////////////////////

#include <Burngine/Window/WindowImpl.hpp>

#if defined(BURNGINE_OS_WINDOWS)

#include <Burngine/Window/Win32/WindowImplWin32.hpp>
typedef burn::priv::WindowImplWin32 WindowImplType;

#elif defined(BURNGINE_OS_LINUX)

#include <Burngine/Window/Unix/WindowImplX11.hpp>
typedef burn::priv::WindowImplX11 WindowImplType;

#endif

namespace burn {
namespace priv {

WindowImpl* WindowImpl::create(	const VideoMode& videoMode,
								const std::string& title,
								const Window::Style& style) {
	return new WindowImplType(videoMode, title, style);
}

WindowImpl::~WindowImpl() {
}

WindowImpl::WindowImpl() :
m_creationSucceeded(true) {

}

bool WindowImpl::creationSucceeded() const {
	return m_creationSucceeded;
}

void WindowImpl::creationFail() {
	m_creationSucceeded = false;
}

bool WindowImpl::popEvent(Event& event) {

	// If we have no events in queue, check for new ones
	if(m_events.empty()){

		// Process window events
		processEvents();

	}

	// Return an event if possible
	if(!m_events.empty()){

		event = m_events.front();
		m_events.pop();
		return true;

	}

	// No events
	return false;
}

void WindowImpl::pushEvent(const Event& event) {
	m_events.push(event);
}

} /* namespace priv */
} /* namespace burn */
