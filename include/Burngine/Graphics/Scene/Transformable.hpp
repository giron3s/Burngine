//////////////////////////////////////////////////////////////////////////////
//
// Burngine is distributed under the GNU LGPL v3 License
// ====================================================
//
//    Copyright (C) 2014 Dominik David (frischer-hering@gmx.de)
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Lesser General Public
//    License as published by the Free Software Foundation;
//    version 3.0 of the License
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
//    USA
//
//////////////////////////////////////////////////////////////////////////////

#ifndef TRANSFORMABLE_HPP_
#define TRANSFORMABLE_HPP_

#include <Burngine/Export.hpp>
#include <Burngine/System/Math.hpp>

namespace burn {

	class BURNGINE_API_EXPORT Transformable {
	public:

		/**
		 * @brief Set default values
		 */
		Transformable();

		/**
		 * @brief Copy values
		 */
		Transformable(const Transformable& other);

		/**
		 * @brief assign values
		 */
		Transformable& operator=(const Transformable& other);

		/**
		 * @brief Set new position values
		 *
		 * @param position New values
		 */
		void setPosition(const Vector3f& position);

		/**
		 * @brief Get position values
		 *
		 * @return current position values
		 */
		const Vector3f& getPosition() const;

		/**
		 * @brief Set new rotation values
		 *
		 * @param rotation New values
		 */
		void setRotation(const Vector3f& rotation);

		/**
		 * @brief Get rotation values
		 *
		 * @return current rotation values
		 */
		const Vector3f& getRotation() const;

		/**
		 * @brief Set new scale values
		 *
		 * @param scale New values
		 */
		void setScale(const Vector3f& scale);

		/**
		 * @brief Get scale values
		 *
		 * @return current scale values
		 */
		const Vector3f& getScale() const;

	private:
		Vector3f m_position;
		Vector3f m_rotation;
		Vector3f m_scale;
	};

} /* namespace burn */

#endif /* TRANSFORMABLE_HPP_ */
