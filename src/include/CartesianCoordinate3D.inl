//
// $Id$: $Date$
//

/*!
  \file 
 
  \brief inline implementations for the CartesianCoordinate3D<coordT> class 

  \author Sanida Mustafovic 
  \author Kris Thielemans 
  \author PARAPET project

  \date    $Date$

  \version $Revision$

*/


START_NAMESPACE_TOMO

template <class coordT>
CartesianCoordinate3D<coordT>::CartesianCoordinate3D()
  : Coordinate3D<coordT>()
{}

template <class coordT>
CartesianCoordinate3D<coordT>::CartesianCoordinate3D(const coordT& z, 
						     const coordT& y, 
						     const coordT& x)
  : Coordinate3D<coordT>(z,y,x)
{}


template <class coordT>
CartesianCoordinate3D<coordT>::CartesianCoordinate3D(const basebase_type& c)
  : base_type(c)
{}



template <class coordT>
CartesianCoordinate3D<coordT>& 
CartesianCoordinate3D<coordT>:: operator=(const basebase_type& c)
{
  basebase_type::operator=(c);
  return *this;
}

// Point3D to CartesianCoordinate3D

template <class coordT>
CartesianCoordinate3D<coordT> ::CartesianCoordinate3D(const Point3D& p)

{
  x() = p.x;
  y() = p.y;
  z() = p.z;
}

template <class coordT>
coordT&
CartesianCoordinate3D<coordT>::z()
{
  return operator[](1);
}


template <class coordT>
coordT
CartesianCoordinate3D<coordT>::z() const
{
  return operator[](1);
}


template <class coordT>
coordT&
CartesianCoordinate3D<coordT>::y()
{
  return operator[](2);
}


template <class coordT>
coordT
CartesianCoordinate3D<coordT>::y() const
{
  return operator[](2);
}


template <class coordT>
coordT&
CartesianCoordinate3D<coordT>::x()
{
  return operator[](3);
}


template <class coordT>
coordT
CartesianCoordinate3D<coordT>::x() const
{
  return operator[](3);
}


END_NAMESPACE_TOMO
