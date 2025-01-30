#ifndef __MESH_H_
#define __MESH_H_

#include "Definitions.h"
#include "Shader.h"
#include <vector>

typedef std::vector<ASH::Vector3> VectorList;

namespace ASH
{
	/// <summary>
	/// Flags the type of vertices being inserted into an instance of the Mesh object.
	/// </summary>
	enum VertexType
	{
		Undefined,
		VertexPosition,
		VertexPositionColor
	};

	/// <summary>
	/// Contains the most basic data and information for models and primitives.
	/// Vertex cloud data container.
	/// </summary>
	class ASH_API Mesh
	{
	private:
		GLuint m_VBO;				// Vertex Buffer Object
		GLuint m_VAO;				// Vertex Array Object
		VectorList m_lVertices;		// List of Vertices
		VertexType m_VertexType;	// Type of Vertices in the buffers.
		int m_dVertexCount;			// Total Amount of Vertices.
		Shader* m_pShader;			// Shader for this Mesh.

	public:
		/// <summary>
		/// Constructs an instance of the Mesh object.
		/// </summary>
		Mesh();

		/// <summary>
		/// Mesh class destructor.
		/// </summary>
		~Mesh(void);

		/// <summary>
		/// Copy constructor for the Mesh copy constructor.
		/// </summary>
		/// <param name="other">Reference to the Mesh being copied.</param>
		Mesh(const Mesh& other);

		/// <summary>
		/// Copy operator for the Mesh class.
		/// </summary>
		/// <param name="other">The other Mesh object being copied.</param>
		/// <returns>A reference to the new Mesh object.</returns>
		Mesh& operator= (const Mesh& other);

		/// <summary>
		/// Adds a Vertex position to the list of vertices.
		/// </summary>
		/// <param name="a_v3VertexPosition">Vector3 position of the vertex.</param>
		void AddVertex(Vector3 a_v3VertexPosition);

		/// <summary>
		/// Adds a Vertex color and position to the list of vertices.
		/// </summary>
		/// <param name="a_v3VertexPosition">The Vector3 position of the Vertex.</param>
		/// <param name="a_v3VertexColor">The Vector3 RGB color of the Vertex.</param>
		void AddVertexColor(Vector3 a_v3VertexPosition, Vector3 a_v3VertexColor);

		/// <summary>
		/// Clears the list of vertices and resets member fields.
		/// </summary>
		void Clear(void);

		/// <summary>
		/// Calls all necessary OpenGL functionalities to set this Mesh's buffers.
		/// </summary>
		void CompileMesh();

		/// <summary>
		/// Renders this Mesh's buffers to the window.
		/// </summary>
		void Render();

	private:

		/// <summary>
		/// Resets the vbo and vao objects in addition to the enum flag.
		/// </summary>
		void Reset(void);
	};
}

#endif //__MESH_H_