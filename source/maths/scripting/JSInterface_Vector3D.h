// JSInterface_Entity.h
//
// 
// A JavaScript class representing a Prometheus CVector3D object.
//
// Usage: Used when manipulating objects of class 'Vector3D' in JavaScript.
//
// Mark Thompson mot20@cam.ac.uk / mark@wildfiregames.com

#include "scripting/ScriptingHost.h"
#include "Vector3D.h"

#ifndef JSI_VECTOR3_INCLUDED
#define JSI_VECTOR3_INCLUDED

class IBoundPropertyOwner;

namespace JSI_Vector3D
{
	enum 
	{
		component_x,
		component_y,
		component_z
	};
	JSBool toString( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );
	struct Vector3D_Info
	{
		IBoundPropertyOwner* owner;
		void ( IBoundPropertyOwner::*updateFn )();
		CVector3D* vector;
		Vector3D_Info();
		Vector3D_Info( float x, float y, float z );
		Vector3D_Info( const CVector3D& copy );
		Vector3D_Info( CVector3D* attach, IBoundPropertyOwner* _owner );
		Vector3D_Info( CVector3D* attach, IBoundPropertyOwner* _owner, void (IBoundPropertyOwner::*_updateFn)() );
		~Vector3D_Info();
	};
	extern JSClass JSI_class;
	extern JSPropertySpec JSI_props[];
	extern JSFunctionSpec JSI_methods[];
	JSBool getProperty( JSContext* cx, JSObject* obj, jsval id, jsval* vp );
    JSBool setProperty( JSContext* cx, JSObject* obj, jsval id, jsval* vp );
	void finalize( JSContext* cx, JSObject* obj );
	JSBool construct( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );
    void init();
}

#endif

