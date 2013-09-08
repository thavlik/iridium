#pragma once

#pragma once

template<class T> inline T degtorad(const T& v)
{
	return v * 0.0174532925;
}

template<class T> inline T radtodeg(const T& v)
{
	return v * 57.2957795;
}

template<class T>
class TVec2
{
public:
	union
	{
		T _vec[2];
		struct { T x, y; };
		struct { T r, g; };
		struct { T s, t; };
	};

	TVec2()
		: x(0), y(0) { }

	TVec2(T x, T y)
		: x(x), y(y) { }

	explicit TVec2(const T* p)
		: x(p[0]), y(p[1]) { }

	explicit TVec2(T n)
		: x(n), y(n) { }

	template<class T2> operator TVec2<T2>() const { return TVec2<T2>( (T2)x, (T2)y ); }

	template<class T2> TVec2(const TVec2<T2>& b)
		: x( (T)b.x )
		, y( (T)b.y ) { }

	TVec2 Abs() const { return TVec2( abs(x), abs(y) ); }

	TVec2 Floor() const { return TVec2( floor(x), floor(y) ); }

	TVec2 Ceil() const { return TVec2( ceil(x), ceil(y) ); }

	T Dot(const TVec2& b) const { return x*b.x + y*b.y; }

	T LengthSq() const { return Dot(*this); }

	T Length() const { return sqrt(LengthSq()); }

	T ManhattanLength() const
	{
		const TVec2 a = Abs();
		return a.x + a.y;
	}

	T ChebyshevLength() const
	{
		const TVec2 a = Abs();
		return a.x > a.y ? a.x : a.y;
	}

	T QuadLength() const
	{
		return (x*x + y*y) + (x*y);
	}

	T Minkowski4Length() const
	{
		return  pow(x*x*x*x + y*y*y*y, 0.25);
	}

	T Minkowski5Length() const
	{
		const T p = 0.5;
		return pow(
			  pow( fabs(x), p )
			+ pow( fabs(y), p ),
			1.0/p
			);
	}

	TVec2 operator-() const { return TVec2(-x, -y); }

	TVec2 operator+(T a) const { return TVec2(x + a, y + a); }
	TVec2 operator-(T a) const { return TVec2(x - a, y - a); }
	TVec2 operator*(T a) const { return TVec2(x * a, y * a); }
	TVec2 operator/(T a) const { return TVec2(x / a, y / a); }
	TVec2& operator+=(T a) const { x += a; y += a; return *this; }
	TVec2& operator-=(T a) const { x -= a; y -= a; return *this; }
	TVec2& operator*=(T a) const { x *= a; y *= a; return *this; }
	TVec2& operator/=(T a) const { x /= a; y /= a; return *this; }

	TVec2 operator+(const TVec2<T>& a) const { return TVec2(x + a.x, y + a.y); }
	TVec2 operator-(const TVec2<T>& a) const { return TVec2(x - a.x, y - a.y); }
	TVec2 operator*(const TVec2<T>& a) const { return TVec2(x * a.x, y * a.y); }
	TVec2 operator/(const TVec2<T>& a) const { return TVec2(x / a.x, y / a.y); }
	TVec2& operator+=(const TVec2<T>& a) { x += a.x; y += a.y; return *this; }
	TVec2& operator-=(const TVec2<T>& a) { x -= a.x; y -= a.y; return *this; }
	TVec2& operator*=(const TVec2<T>& a) { x *= a.x; y *= a.y; return *this; }
	TVec2& operator/=(const TVec2<T>& a) { x /= a.x; y /= a.y; return *this; }

	inline T const* ToPtr() const { return _vec; }
	inline T* ToPtr() { return _vec; }

	T& operator[](int idx) { return _vec[idx]; }
	T operator[](int idx) const { return _vec[idx]; }
};


template<class T>
class TVec3
{
public:
	union
	{
		T _vec[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { T s, t, u; };
	};

	TVec3()
		: x(0), y(0), z(0) { }

	TVec3(T x, T y, T z)
		: x(x), y(y), z(z) { }

	explicit TVec3(const T* p)
		: x(p[0]), y(p[1]), z(p[2]) { }

	explicit TVec3(T n)
		: x(n), y(n), z(n) { }

	template<class T2> operator TVec3<T2>() const { return TVec3<T2>( (T2)x, (T2)y, (T2)z ); }

	template<class T2> TVec3(const TVec3<T2>& b)
		: x( (T)b.x )
		, y( (T)b.y )
		, z( (T)b.z ) { }

	TVec3 Abs() const { return TVec3( abs(x), abs(y), abs(z) ); }

	TVec3 Floor() const { return TVec3( floor(x), floor(y), floor(z) ); }

	TVec3 Ceil() const { return TVec3( ceil(x), ceil(y), ceil(z) ); }

	T Dot(const TVec3& v) const { return x*v.x + y*v.y + z*v.z; }

	TVec3 Cross(const TVec3& b) const {
		return TVec3(
			y*b.z - z*b.y,
			z*b.x - x*b.z,
			x*b.y - y*b.x);
	}

	T LengthSq() const { return Dot(*this); }

	T Length() const { return sqrt(LengthSq()); }

	T ManhattanLength() const {
		const TVec3 a = Abs();
		return a.x + a.y + a.z;
	}

	T ChebyshevLength() const {
		const TVec3 a = Abs();
		return a.x > a.y
			? (a.x > a.z ? a.x : a.z)
			: (a.y > a.z ? a.y : a.z);
	}

	T QuadLength() const
	{
		return (x*x + y*y + z*z) + (x*y + x*z) + (y*z);
	}

	T Minkowski4Length() const
	{
		return pow(pow(x,4) + pow(y,4) + pow(z,4), 0.25);
	}

	T Minkowski5Length() const
	{
		const T p = 0.5;
		return pow(
			pow( fabs(x), p )
			+ pow( fabs(y), p )
			+ pow( fabs(z), (T)2.7182818284 ),
			1.0/p
			);
	}

	TVec3 Normalized() const {
		const T len = Length();
		return TVec3(x / len, y / len, z / len);
	}

	void Normalize() {
		const T len = Length();
		x /= len;
		y /= len;
		z /= len;
	}

public:
	TVec3 operator +(const TVec3& b) const {
		return TVec3(x + b.x, y + b.y, z + b.z);
	}
	TVec3 operator -(const TVec3& b) const {
		return TVec3(x - b.x, y - b.y, z - b.z);
	}

	void operator +=(const TVec3& b) {
		x += b.x;
		y += b.y;
		z += b.z;
	}
	void operator -=(const TVec3& b) {
		x -= b.x;
		y -= b.y;
		z -= b.z;
	}

	inline T const* ToPtr() const { return _vec; }

	inline T* ToPtr() { return _vec; }

	TVec3 operator-() const { return TVec3(-x, -y, -z); }

	TVec3 operator*(T n) const { return TVec3(x*n, y*n, z*n); }
	TVec3 operator/(T n) const { return TVec3(x/n, y/n, z/n); }

	void operator*=(T n) { x *= n; y *= n; z *= n; }
	void operator/=(T n) { x /= n; y /= n; z /= n; }

	T &operator[](int idx) { return *((&x)+idx); }
	T operator[](int idx) const { return *((&x)+idx); }
};

template<class T>
class TVec4
{
public:
	union
	{
		T _vec[4];
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		struct { T s, t, u, v; };
	};

	TVec4()
		: x(0), y(0), z(0), w(0) { }

	TVec4(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w) { }

	explicit TVec4(const T* p)
		: x(p[0]), y(p[1]), z(p[2]), w(p[3]) { }

	explicit TVec4(T n)
		: x(n), y(n), z(n), w(n) { }

	template<class T2> operator TVec4<T2>() const { return TVec4<T2>( (T2)x, (T2)y, (T2)z, (T2)w ); }

	template<class T2> TVec4(const TVec4<T2>& b)
		: x( (T)b.x )
		, y( (T)b.y )
		, z( (T)b.z )
		, w( (T)b.w ) { }

	TVec4 Abs() const { return TVec4( abs(x), abs(y), abs(z), abs(w) ); }

	TVec4 Floor() const { return TVec4( floor(x), floor(y), floor(z), floor(w) ); }

	TVec4 Ceil() const { return TVec4( ceil(x), ceil(y), ceil(z), ceil(w) ); }

	TVec4 Cross(const TVec4& b) const {
		return TVec4(
			y*b.z - z*b.y,
			z*b.x - x*b.z,
			x*b.y - y*b.x,
			1.0);
	}

	T Dot(const TVec4& v) const { return x*v.x + y*v.y + z*v.z + w*v.w; }

	T LengthSq() const { return Dot(*this); }

	T Length() const { return sqrt(LengthSq()); }

	T ManhattanLength() const
	{
		const TVec4 a = Abs();
		return a.x + a.y + a.z + a.w;
	}

	T ChebyshevLength() const {
		const TVec4 a = Abs();
		return a.x > a.y
			? (a.x > a.z ? (a.x > a.w ? a.x : a.w) : a.z)
			: (a.y > a.z ? (a.y > a.w ? a.y : a.w) : a.z);
	}

	T QuadLength() const
	{
		return (x*x + y*y + z*z + w*w) + (x*y + x*z + x*w) + (y*z + y*w) + (z*w);
	}

	T Minkowski4Length() const
	{
		return pow(pow(x,4) + pow(y,4) + pow(z,4) + pow(w,4), 0.25);
	}

	T Minkowski5Length() const
	{
		const T p = 0.5;
		return pow(
			  pow( fabs(x), p )
			+ pow( fabs(y), p )
			+ pow( fabs(z), (T)2.7182818284 )
			+ pow( fabs(w), (T)2.7182818284 ),
			1.0/p
			);
	}

	TVec4 operator+(const TVec4& v) const { return TVec4(x+v.x, y+v.y, z+v.z, w+v.w); }
	TVec4 operator-(const TVec4& v) const { return TVec4(x-v.x, y-v.y, z-v.z, w-v.w); }
	TVec4 operator*(const TVec4& v) const { return TVec4(x*v.x, y*v.y, z*v.z, w*v.w); }
	TVec4 operator/(const TVec4& v) const { return TVec4(x/v.x, y/v.y, z/v.z, w/v.w); }

	TVec4 operator*(T a) const { return TVec4(x*a, y*a, z*a, w*a); }
	TVec4 operator/(T a) const { return TVec4(x/a, y/a, z/a, w/a); }
	void operator*=(T n) { x *= n; y *= n; z *= n; w *= n; }
	void operator/=(T n) { x /= n; y /= n; z /= n; w /= n; }

	inline T const* ToPtr() const { return _vec; }

	inline T* ToPtr() { return _vec; }
};

template<class T>
class TAngles
{
public:
	T yaw, pitch, roll;

	TAngles()
		: yaw(0.0), pitch(0.0), roll(0.0) { }

	TAngles(T yaw, T pitch, T roll)
		: yaw(yaw), pitch(pitch), roll(roll) { }

	explicit TAngles(const T* p)
		: yaw(p[0]), pitch(p[1]), roll(p[2]) { }

	explicit TAngles(T v)
		: yaw(v), pitch(v), roll(v) { }

	TVec3<T> x() const
	{
		const T sy(sin(yaw));
		const T sp(sin(pitch));
		const T cy(cos(yaw));
		const T cp(cos(pitch));
		return TVec3<T>(cp*cy, sy*cp, sp);
	}
	TVec3<T> y() const
	{
		const T sy(sin(yaw));
		const T sp(sin(pitch));
		const T sr(sin(roll));
		const T cy(cos(yaw));
		const T cp(cos(pitch));
		const T cr(cos(roll));
		return TVec3<T>(sr*sp*cy + cr*-sy, sr*sp*sy + cr*cy, -sr*cp);
	}
	TVec3<T> z() const
	{
		const T sy(sin(yaw));
		const T sp(sin(pitch));
		const T sr(sin(roll));
		const T cy(cos(yaw));
		const T cp(cos(pitch));
		const T cr(cos(roll));	
		return TVec3<T>(cr*sp*cy+-sr*-sy, cr*sp*sy+-sr*cy, cr*cp);
	}
};

template<class T>
class TMatrix3
{
public:
	TVec3<T> x, y, z;

	TMatrix3()
		: x(1.0, 0.0, 0.0) 
		, y(0.0, 1.0, 0.0)
		, z(0.0, 0.0, 1.0) { }

	TMatrix3(const TVec3<T>& x, const TVec3<T>& y, const TVec3<T>& z)
		: x(x), y(y), z(z) { }

	explicit TMatrix3(const T* p)
	{
		memcpy( this, p, sizeof(TMatrix3<T>) );
	}

	void Transpose() { *this = Transposed(); }

	void Invert() { *this = Inverted(); }

	TMatrix3<T> Transposed() const
	{
		return TMatrix3<T>(
			TVec3<T>(this->x.x, this->x.y, this->x.z),
			TVec3<T>(this->y.x, this->y.y, this->y.z),
			TVec3<T>(this->z.x, this->z.y, this->z.z)
			);
	}

	TMatrix3<T> Inverted() const
	{
		const T a = this->x.x, b = this->x.y, c = this->x.z,
				d = this->y.x, e = this->y.y, f = this->y.z,
				g = this->z.x, h = this->z.y, i = this->z.z;

		const float detA = a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;

		if(detA == 0)
			return TMatrix3<T>();

		const float invDetA = 1.0f / detA;

		return TMatrix3<T>(
			TVec3<T>( (e*i-h*f)*invDetA, (c*h-i*b)*invDetA, (b*f-e*c)*invDetA ),
			TVec3<T>( (f*g-i*d)*invDetA, (a*i-g*c)*invDetA, (c*d-f*a)*invDetA ),
			TVec3<T>( (d*h-g*e)*invDetA, (b*g-h*a)*invDetA, (a*e-d*b)*invDetA )
		);
	}

	static TMatrix3<T> Rotate(T radians)
	{
		const T sx = sin(radians);
		const T cx = cos(radians);
		return TMatrix3<T>
			(
			TVec3<T>(cx,	sx,		0.0),
			TVec3<T>(-sx,	cx,		0.0),
			TVec3<T>(0.0,	0.0,	1.0)
			);
	}

	static TMatrix3<T> Scale(T x, T y)
	{
		return TMatrix3<T>(
			TVec3<T>(x,		0.0,	0.0),
			TVec3<T>(0.0,	y,		0.0),
			TVec3<T>(0.0,	0.0,	1.0)
			);
	}

	static TMatrix3<T> Scale(const TVec2<T>& v)
	{
		return Scale(v.x, v.y);
	}

	static TMatrix3<T> Translate(T x, T y)
	{
		return TMatrix3<T>(
			1.0,	0.0,	0.0,
			0.0,	1.0,	0.0,
			x,		y,		1.0
			);
	}

	static TMatrix3<T> Translate(const TVec2<T>& v)
	{
		return Translate(v.x, v.y);
	}

	TMatrix3<T> operator*(const TMatrix3<T>& b) const
	{
		return TMatrix3<T>(
			TVec3<T>(
				(this->x.x * b.x.x) + (this->x.y * b.y.x) + (this->x.z * b.z.x),
				(this->x.x * b.x.y) + (this->x.y * b.y.y) + (this->x.z * b.z.y),
				(this->x.x * b.x.z) + (this->x.y * b.y.z) + (this->x.z * b.z.z)),
			TVec3<T>(
				(this->y.x * b.x.x) + (this->y.y * b.y.x) + (this->y.z * b.z.x),
				(this->y.x * b.x.y) + (this->y.y * b.y.y) + (this->y.z * b.z.y),
				(this->y.x * b.x.z) + (this->y.y * b.y.z) + (this->y.z * b.z.z)),
			TVec3<T>(
				(this->z.x * b.x.x) + (this->z.y * b.y.x) + (this->z.z * b.z.x),
				(this->z.x * b.x.y) + (this->z.y * b.y.y) + (this->z.z * b.z.y),
				(this->z.x * b.x.z) + (this->z.y * b.y.z) + (this->z.z * b.z.z))
		);
	}

	TVec2<T> operator *(const TVec2<T>& a) const
	{
		return TVec2<T>(
			this->x.x*a.x + this->y.x*a.y + this->z.x,
			this->x.y*a.x + this->y.y*a.y + this->z.y
		);
	}
};

template<class T>
class TMatrix4
{
public:
	TVec4<T> x, y, z, w;

	TMatrix4()
		: x(1.0, 0.0, 0.0, 0.0)
		, y(0.0, 1.0, 0.0, 0.0)
		, z(0.0, 0.0, 1.0, 0.0)
		, w(0.0, 0.0, 0.0, 1.0) { }

	TMatrix4(const TVec4<T>& x, const TVec4<T>& y, const TVec4<T>& z, const TVec4<T>& w)
		: x(x), y(y), z(z), w(w) { }

	explicit TMatrix4(const T* p)
	{
		memcpy( this, p, sizeof(TMatrix4<T>) );
	}

	TMatrix4<T> Inverted() const
	{
		TMatrix4<T> inv;

		inv.x.x
			= this->y.y * this->z.z * this->w.w
			- this->y.y * this->z.w * this->w.z
			- this->z.y * this->y.z * this->w.w
			+ this->z.y * this->y.w * this->w.z
			+ this->w.y * this->y.z * this->z.w
			- this->w.y * this->y.w * this->z.z;

		inv.y.x
			= -this->y.x * this->z.z * this->w.w
			+ this->y.x * this->z.w * this->w.z 
			+ this->z.x * this->y.z * this->w.w
			- this->z.x * this->y.w * this->w.z
			- this->w.x * this->y.z * this->z.w
			+ this->w.x * this->y.w * this->z.z;

		inv.z.x
			= this->y.x * this->z.y * this->w.w
			- this->y.x * this->z.w * this->w.y
			- this->z.x * this->y.y * this->w.w
			+ this->z.x * this->y.w * this->w.y
			+ this->w.x * this->y.y * this->z.w
			- this->w.x * this->y.w * this->z.y;

		inv.w.x
			= -this->y.x  * this->z.y * this->w.z
			+ this->y.x  * this->z.z * this->w.y
			+ this->z.x  * this->y.y * this->w.z
			- this->z.x  * this->y.z * this->w.y
			- this->w.x * this->y.y * this->z.z
			+ this->w.x * this->y.z * this->z.y;

		inv.x.y
			= -this->x.y  * this->z.z * this->w.w
			+ this->x.y  * this->z.w * this->w.z
			+ this->z.y  * this->x.z * this->w.w
			- this->z.y  * this->x.w * this->w.z
			- this->w.y * this->x.z * this->z.w
			+ this->w.y * this->x.w * this->z.z;

		inv.y.y
			= this->x.x  * this->z.z * this->w.w
			- this->x.x  * this->z.w * this->w.z
			- this->z.x  * this->x.z * this->w.w
			+ this->z.x  * this->x.w * this->w.z
			+ this->w.x * this->x.z * this->z.w
			- this->w.x * this->x.w * this->z.z;

		inv.z.y
			= -this->x.x  * this->z.y * this->w.w
			+ this->x.x  * this->z.w * this->w.y
			+ this->z.x  * this->x.y * this->w.w
			- this->z.x  * this->x.w * this->w.y
			- this->w.x * this->x.y * this->z.w
			+ this->w.x * this->x.w * this->z.y;

		inv.w.y
			= this->x.x  * this->z.y * this->w.z
			- this->x.x  * this->z.z * this->w.y
			- this->z.x  * this->x.y * this->w.z
			+ this->z.x  * this->x.z * this->w.y
			+ this->w.x * this->x.y * this->z.z
			- this->w.x * this->x.z * this->z.y;

		inv.x.z
			= this->x.y  * this->y.z * this->w.w
			- this->x.y  * this->y.w * this->w.z
			- this->y.y  * this->x.z * this->w.w
			+ this->y.y  * this->x.w * this->w.z
			+ this->w.y * this->x.z * this->y.w
			- this->w.y * this->x.w * this->y.z;

		inv.y.z
			= -this->x.x  * this->y.z * this->w.w
			+ this->x.x  * this->y.w * this->w.z
			+ this->y.x  * this->x.z * this->w.w
			- this->y.x  * this->x.w * this->w.z
			- this->w.x * this->x.z * this->y.w
			+ this->w.x * this->x.w * this->y.z;

		inv.z.z
			= this->x.x  * this->y.y * this->w.w
			- this->x.x  * this->y.w * this->w.y
			- this->y.x  * this->x.y * this->w.w
			+ this->y.x  * this->x.w * this->w.y
			+ this->w.x * this->x.y * this->y.w
			- this->w.x * this->x.w * this->y.y;

		inv.w.z
			= -this->x.x  * this->y.y * this->w.z
			+ this->x.x  * this->y.z * this->w.y
			+ this->y.x  * this->x.y * this->w.z
			- this->y.x  * this->x.z * this->w.y
			- this->w.x * this->x.y * this->y.z
			+ this->w.x * this->x.z * this->y.y;

		inv.x.w
			= -this->x.y * this->y.z * this->z.w
			+ this->x.y * this->y.w * this->z.z
			+ this->y.y * this->x.z * this->z.w
			- this->y.y * this->x.w * this->z.z
			- this->z.y * this->x.z * this->y.w
			+ this->z.y * this->x.w * this->y.z;

		inv.y.w
			= this->x.x * this->y.z * this->z.w
			- this->x.x * this->y.w * this->z.z
			- this->y.x * this->x.z * this->z.w
			+ this->y.x * this->x.w * this->z.z
			+ this->z.x * this->x.z * this->y.w
			- this->z.x * this->x.w * this->y.z;

		inv.z.w
			= -this->x.x * this->y.y * this->z.w
			+ this->x.x * this->y.w * this->z.y
			+ this->y.x * this->x.y * this->z.w
			- this->y.x * this->x.w * this->z.y
			- this->z.x * this->x.y * this->y.w
			+ this->z.x * this->x.w * this->y.y;

		inv.w.w 
			= this->x.x * this->y.y * this->z.z
			- this->x.x * this->y.z * this->z.y
			- this->y.x * this->x.y * this->z.z
			+ this->y.x * this->x.z * this->z.y
			+ this->z.x * this->x.y * this->y.z
			- this->z.x * this->x.z * this->y.y;

		T det
			= this->x.x * inv.x.x
			+ this->x.y * inv.y.x
			+ this->x.z * inv.z.x
			+ this->x.w * inv.w.x;

		if(det == 0)
			return TMatrix4<T>();

		det = 1.0 / det;

		TMatrix4<T> invOut;

		invOut.x = inv.x * det;
		invOut.y = inv.y * det;
		invOut.z = inv.z * det;
		invOut.w = inv.w * det;

		return invOut;
	}

	TMatrix4<T> Transposed() const
	{
		return TMatrix4<T>(
			TVec4<T>(this->x.x, this->x.y, this->x.z, this->x.w),
			TVec4<T>(this->y.x, this->y.y, this->y.z, this->y.w),
			TVec4<T>(this->z.x, this->z.y, this->z.z, this->z.w),
			TVec4<T>(this->w.x, this->w.y, this->w.z, this->w.w)
		);
	}

	void Invert() { *this = Inverted(); }

	void Transpose() { *this = Transposed(); }

public:
	static TMatrix4<T> Rotate(const TAngles<T>& angles)
	{
		return Rotatez(angles.yaw)
			* Rotatey(angles.pitch)
			* Rotatex(angles.roll);
	}
	static TMatrix4<T> RotateX(T a)
	{
		return TMatrix4<T>(
			TVec4<T>(0.0,  0.0,    0.0,    0.0),
			TVec4<T>(0.0,  cos(a), sin(a), 0.0),
			TVec4<T>(0.0, -sin(a), cos(a), 0.0),
			TVec4<T>(0.0,  0.0,    0.0,    1.0)
		);
	}
	static TMatrix4<T> RotateY(T a)
	{
		return TMatrix4<T>(
			TVec4<T>(cos(a), 0.0, -sin(a), 0.0),
			TVec4<T>(0.0,    1.0,  0.0,    0.0),
			TVec4<T>(sin(a), 0.0,  cos(a), 0.0),
			TVec4<T>(0.0,    0.0,  0.0,    1.0)
		);
	}
	static TMatrix4<T> RotateZ(T a)
	{
		return TMatrix4<T>(
			TVec4<T>( cos(a), sin(a), 0.0, 0.0),
			TVec4<T>(-sin(a), cos(a), 0.0, 0.0),
			TVec4<T>( 0.0,    0.0,    1.0, 0.0),
			TVec4<T>( 0.0,    0.0,    0.0, 1.0)
		);
	}
	static TMatrix4<T> Translate(T x, T y, T z)
	{
		return TMatrix4<T>(
			TVec4<T>(1.0, 0.0, 0.0, 0.0),
			TVec4<T>(0.0, 1.0, 0.0, 0.0),
			TVec4<T>(0.0, 0.0, 1.0, 0.0),
			TVec4<T>(x,   y,   z,   1.0)
		);
	}
	static TMatrix4<T> Translate(const TVec3<T>& v)
	{
		return Translate(v.x, v.y, v.z);
	}
	static TMatrix4<T> Scale(T x, T y, T z)
	{
		return TMatrix4<T>(
			TVec4<T>(x,   0.0, 0.0, 0.0),
			TVec4<T>(0.0, y,   0.0, 0.0),
			TVec4<T>(0.0, 0.0, z,   0.0),
			TVec4<T>(0.0, 0.0, 0.0, 1.0)
			);
	}
	static TMatrix4<T> Scale(const TVec3<T>& v)
	{
		return Scale(v.x, v.y, v.z);
	}
	static TMatrix4<T> Perspective(T zn, T zf, T aspect, T fovyradians)
	{
		const T ymax = zn * tanf(fovyradians * 0.5); // fovydegrees * (T)(M_PI) / 360.0f

		const T xmax = ymax * aspect;

		return Frustum(-xmax, xmax, -ymax, ymax, zn, zf);
	}
	static TMatrix4<T> Frustum(T left, T right, T bottom, T top, T znear, T zfar)
	{
		const T temp = 2.0 * znear;
		const T temp2 = right - left;
		const T temp3 = top - bottom;
		const T temp4 = zfar - znear;
		TMatrix4<T> m;
		m.x.x = temp / temp2;
		m.x.y = 0.0;
		m.x.z = 0.0;
		m.x.w = 0.0;
		m.y.x = 0.0;
		m.y.y = temp / temp3;
		m.y.z = 0.0;
		m.y.w = 0.0;
		m.z.x = (right + left) / temp2;
		m.z.y = (top + bottom) / temp3;
		m.z.z = (-zfar - znear) / temp4;
		m.z.w = -1.0;
		m.w.x = 0.0;
		m.w.y = 0.0;
		m.w.z = (-temp * zfar) / temp4;
		m.w.w = 0.0;
		return m;
	}
	static TMatrix4<T> View(const TVec3<T>& eye, const TVec3<T>& at, const TVec3<T>& up)
	{
		const TVec3<T> v0 = ( eye - at     ).Normalized();
		const TVec3<T> v1 = ( up.Cross(v0) ).Normalized();
		const TVec3<T> v2 = ( v0.Cross(v1) ).Normalized();
		const T	r1 = -v1.Dot(eye);
		const T r2 = -v2.Dot(eye);
		const T r3 = -v0.Dot(eye);
		TMatrix4<T> m;
		m.x.x = v1.x;	m.x.y = v2.x;	m.x.z = v0.x;	m.x.w = 0.0;
		m.y.x = v1.y;	m.y.y = v2.y;	m.y.z = v0.y;	m.y.w = 0.0;
		m.z.x = v1.z;	m.z.y = v2.z;	m.z.z = v0.z;	m.z.w = 0.0;
		m.w.x = r1;		m.w.y = r2;		m.w.z = r3;		m.w.w = 1.0;
		return m;
	}

public:
	T const* ToPtr() const { return x.ToPtr(); }

	T* ToPtr() { return x.ToPtr(); }

	TVec3<T> operator*(const TVec3<T>& a) const
	{
		return TVec3<T>(
			this->x.x*a.x + this->y.x*a.y + this->z.x*a.z + this->w.x,
			this->x.y*a.x + this->y.y*a.y + this->z.y*a.z + this->w.y,
			this->x.z*a.x + this->y.z*a.y + this->z.z*a.z + this->w.z);
	}

	TVec4<T> operator*(const TVec4<T>& v) const
	{
		return TVec4<T>(
			(x.x * v.x) + (y.x * v.y) + (z.x * v.z) + (w.x * v.w),
			(x.y * v.x) + (y.y * v.y) + (z.y * v.z) + (w.y * v.w),
			(x.z * v.x) + (y.z * v.y) + (z.z * v.z) + (w.z * v.w),
			(x.w * v.x) + (y.w * v.y) + (z.w * v.z) + (w.w * v.w));
	}

	TMatrix4 operator*(const TMatrix4<T>& b) const
	{
		return TMatrix4<T>
		(
			TVec4<T>(
				(this->x.x * b.x.x) + (this->x.y * b.y.x) + (this->x.z * b.z.x) + (this->x.w * b.w.x),
				(this->x.x * b.x.y) + (this->x.y * b.y.y) + (this->x.z * b.z.y) + (this->x.w * b.w.y),
				(this->x.x * b.x.z) + (this->x.y * b.y.z) + (this->x.z * b.z.z) + (this->x.w * b.w.z),
				(this->x.x * b.x.w) + (this->x.y * b.y.w) + (this->x.z * b.z.w) + (this->x.w * b.w.w)
			),
			TVec4<T>(
				(this->y.x * b.x.x) + (this->y.y * b.y.x) + (this->y.z * b.z.x) + (this->y.w * b.w.x),
				(this->y.x * b.x.y) + (this->y.y * b.y.y) + (this->y.z * b.z.y) + (this->y.w * b.w.y),
				(this->y.x * b.x.z) + (this->y.y * b.y.z) + (this->y.z * b.z.z) + (this->y.w * b.w.z),
				(this->y.x * b.x.w) + (this->y.y * b.y.w) + (this->y.z * b.z.w) + (this->y.w * b.w.w)
			),
			TVec4<T>(
				(this->z.x * b.x.x) + (this->z.y * b.y.x) + (this->z.z * b.z.x) + (this->z.w * b.w.x),
				(this->z.x * b.x.y) + (this->z.y * b.y.y) + (this->z.z * b.z.y) + (this->z.w * b.w.y),
				(this->z.x * b.x.z) + (this->z.y * b.y.z) + (this->z.z * b.z.z) + (this->z.w * b.w.z),
				(this->z.x * b.x.w) + (this->z.y * b.y.w) + (this->z.z * b.z.w) + (this->z.w * b.w.w)
			),
			TVec4<T>(
				(this->w.x * b.x.x) + (this->w.y * b.y.x) + (this->w.z * b.z.x) + (this->w.w * b.w.x),
				(this->w.x * b.x.y) + (this->w.y * b.y.y) + (this->w.z * b.z.y) + (this->w.w * b.w.y),
				(this->w.x * b.x.z) + (this->w.y * b.y.z) + (this->w.z * b.z.z) + (this->w.w * b.w.z),
				(this->w.x * b.x.w) + (this->w.y * b.y.w) + (this->w.z * b.z.w) + (this->w.w * b.w.w)
			)
		);
	}
};

typedef TVec2<float>			vec2f;
typedef TVec3<float>			vec3f;
typedef TVec4<float>			vec4f;

typedef TVec2<int>				vec2i;
typedef TVec3<int>				vec3i;
typedef TVec4<int>				vec4i;

typedef TVec2<unsigned>			vec2u;
typedef TVec3<unsigned>			vec3u;
typedef TVec4<unsigned>			vec4u;

typedef TVec2<unsigned short>	vec2s;

typedef TVec2<char>				vec2c;
typedef TVec3<char>				vec3c;
typedef TVec4<char>				vec4c;

typedef TVec2<unsigned char>	vec2b;
typedef TVec3<unsigned char>	vec3b;
typedef TVec4<unsigned char>	vec4b;

typedef TMatrix3<float>			mat3f;
typedef TMatrix4<float>			mat4f;

typedef TAngles<float>			eul3f;
