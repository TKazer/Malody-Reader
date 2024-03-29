#pragma once

namespace Malody
{
	template <typename T> class Singleton
	{
	protected:
		Singleton() {}
		~Singleton() {}
	public:
		static T& get()
		{
			static T instance{};
			return instance;
		}
	};
}
