#pragma once

namespace Ir {
	class Metric {
	public:
		enum {
			UNSET,
			PERCENT,
			UNITS
		};

		Metric()
			: _type(Metric::UNSET)
			, _amount(0.0f) { }

		Metric(int type, float amount)
			: _type(type)
			, _amount(amount) { }

	public:
		static Metric FromUnits(float amount) { return Metric(Metric::UNITS, amount); }

		static Metric FromPercentage(float amount) { return Metric(Metric::PERCENT, amount); }		

	public:
		int getType() const { return _type; }

		float getAmount() const { return _amount; }

	private:
		int _type;

		float _amount;
	};
}