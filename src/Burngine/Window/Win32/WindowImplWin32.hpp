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

#ifndef WINDOWIMPLWIN32_HPP_
#define WINDOWIMPLWIN32_HPP_

#include <Burngine/Export.hpp>
#include <Burngine/Window/WindowImpl.hpp>
#include <Burngine/Window/VideoMode.hpp>

// Win32 library
#include <windows.h>

namespace burn {
namespace priv {

/**
 * @brief Window implementation on unix systems with X11
 */
class WindowImplWin32 : public WindowImpl {
public:

	/**
	 * @brief Create a window with X11
	 *
	 * @param videoMode Desired video mode
	 * @param title Desired window title
	 */
	WindowImplWin32(const VideoMode& videoMode,
					const std::string& title,
					const Window::Style& style);

	/**
	 * @brief Default destructor
	 * Cleans up.
	 */
	~WindowImplWin32();

	/**
	 * @brief Apply new dimensions
	 *
	 * @param dimensions Desired dimensions
	 */
	virtual void setDimensions(const Vector2i& dimensions);

	/**
	 * @brief Apply new window title
	 *
	 * @param title Desired title
	 */
	virtual void setTitle(const std::string& title);

protected:

	/**
	 * @brief Process all window events.
	 * This will add events to the queue of WindowImpl.
	 */
	virtual void processEvents();

private:

	/**
	 * @brief Disable default constructor
	 */
	WindowImplWin32();

	/**
	 * @brief Basic cleanup calls. Destroys window
	 */
	void cleanup();

	/**
	 * @brief Process a Win32 event
	 */
	void processWin32Event(	UINT,
							WPARAM,
							LPARAM);

	/**
	 * @brief Win32 specific event process function
	 */
	static LRESULT CALLBACK globalWindowProcess(HWND,
												UINT,
												WPARAM,
												LPARAM);

	/**
	 * @brief Register Win32 window class
	 */
	void registerWindowClass();

private:
	HWND m_windowHandle;    ///< Win32 window handle
};

} /* namespace priv */
} /* namespace burn */
#endif /* WINDOWIMPLWIN32_HPP_ */
