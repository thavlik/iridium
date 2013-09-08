#pragma once

namespace Ir {
	class Metric {
	public:
		enum {
			Percentage,
			Units,
			Auto
		};

		Metric()
			: _type(Metric::Auto)
			, _amount(0.0f) { }

		Metric(int type, float amount)
			: _type(type)
			, _amount(amount) { }

	public:
		static Metric FromUnits(float amount) { return Metric(Metric::Units, amount); }

		static Metric FromPercentage(float amount) { return Metric(Metric::Percentage, amount); }		

	public:
		int getType() const { return _type; }

		float getAmount() const { return _amount; }

	private:
		int _type;
		float _amount;
	};
}