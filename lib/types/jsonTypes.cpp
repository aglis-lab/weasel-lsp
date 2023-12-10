#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

Number operator+(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i + j;
				},
				[&ret, i](double j)
				{
					ret = i + j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i + j;
				},
				[&ret, i](double j)
				{
					ret = i + j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator-(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i - j;
				},
				[&ret, i](double j)
				{
					ret = i - j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i - j;
				},
				[&ret, i](double j)
				{
					ret = i - j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator*(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i * j;
				},
				[&ret, i](double j)
				{
					ret = i * j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i * j;
				},
				[&ret, i](double j)
				{
					ret = i * j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator/(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i / j;
				},
				[&ret, i](double j)
				{
					ret = i / j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i / j;
				},
				[&ret, i](double j)
				{
					ret = i / j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator|(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i | j;
				},
				[&ret, i](double j)
				{
					ret = i | (int)j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = (int)i | j;
				},
				[&ret, i](double j)
				{
					ret = (int)i | (int)j;
				}
			), n2);
		}
	), n1);

	return ret;
}


Number& operator+=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i + j;
				},
				[&n1, i](double j)
				{
					n1 = i + j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i + j;
				},
				[&n1, i](double j)
				{
					n1 = i + j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator-=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i - j;
				},
				[&n1, i](double j)
				{
					n1 = i - j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i - j;
				},
				[&n1, i](double j)
				{
					n1 = i - j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator*=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i * j;
				},
				[&n1, i](double j)
				{
					n1 = i * j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i * j;
				},
				[&n1, i](double j)
				{
					n1 = i * j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator/=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i / j;
				},
				[&n1, i](double j)
				{
					n1 = i / j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i / j;
				},
				[&n1, i](double j)
				{
					n1 = i / j;
				}
			), n2);
		}
	), n1);

	return n1;
}
}
