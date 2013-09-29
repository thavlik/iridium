#pragma once

namespace Ir {
	class Measure {
	public:
		enum Policy {
			FIXED,
			PERCENT,
			EXPANDING,
			SHRINKING,
			DONTCARE
		};

		Measure()
			: _policy(DONTCARE), _value(0.0f) { }

		Measure(Policy policy, float value = 0.0)
			: _policy(policy), _value(value) { }

		Policy getPolicy() const { return (Policy)_policy; }

		float getValue() const { return _value; }

	private:
		int _policy;

		float _value;
	};
}