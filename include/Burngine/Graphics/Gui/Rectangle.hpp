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

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <Burngine/Export.hpp>
#include <Burngine/Graphics/Gui/GuiNode.hpp>
#include <Burngine/Graphics/VertexBuffer.hpp>
#include <Burngine/System/Math.hpp>
#include <Burngine/Graphics/VertexArray.hpp>

namespace burn {

	class BURNGINE_API_EXPORT Rectangle : public GuiNode {
	public:

		/**
		 * @brief Sets VAO up
		 */
		Rectangle();

		/**
		 * @brief Set dimensions
		 *
		 * @param dimensions Dimensions
		 */
		void setDimensions(const Vector2f& dimensions);

		/**
		 * @brief Get dimensions
		 *
		 * @return Rectangle's dimensions
		 */
		const Vector2f& getDimensions() const;

		/**
		 * @brief Set new color
		 *
		 * @param color Color
		 */
		void setColor(const Vector4f& color);

		/**
		 * @brief Get current color
		 *
		 * @return Current color
		 */
		const Vector4f& getColor() const;

		/**
		 * @brief Implementation of Renderable's render()
		 */
		virtual void render(const Matrix4f& projection) const;

	private:

		/**
		 * @brief Update vertex buffer data
		 */
		virtual void updateVertexData();

	protected:
		Vector2f m_dimensions;
		Vector4f m_color;    ///< Rectangle's color

	private:
		VertexBuffer m_vertexBuffer;    ///< Vertex buffer
		VertexArray m_vertexArray; ///< Vertex array
	};

} /* namespace burn */

#endif /* RECTANGLE_HPP_ */
