#include "Binding.h"
#include "Properties.h"

namespace Ir
{
	void Binding::SetSourceSubscription(bool sync)
	{
		if(sync) {
			_source->OnChanged += Subscriber<Property*>::FromMethod<Binding, &Binding::OnSourceChanged>(this);
		} else {
			_source->OnChanged -= Subscriber<Property*>::FromMethod<Binding, &Binding::OnSourceChanged>(this);
		}
	}
	void Binding::SetSinkSubscription(bool sync)
	{
		if(sync) {
			_sink->OnChanged += Subscriber<Property*>::FromMethod<Binding, &Binding::OnSinkChanged>(this);
		} else {
			_sink->OnChanged -= Subscriber<Property*>::FromMethod<Binding, &Binding::OnSinkChanged>(this);
		}
	}

	Binding::Binding(Property* source, Property* sink, int mode)
		: _source(source)
		, _sink(sink)
		, _mode(mode) {
		if(_mode & Normal)
			SetSourceSubscription(true);
		if(_mode & Reverse)
			SetSinkSubscription(true);
	}

	Binding::~Binding() {
		if((_mode & Normal) != 0)
			SetSourceSubscription(false);
		if((_mode & Reverse) != 0)
			SetSinkSubscription(false);
	}

	void Binding::setMode(int mode) {
		// Update source subs.
		if((mode & Normal) == 0) {
			if((_mode & Normal) != 0)	
				SetSourceSubscription(false);
		}
		else if((_mode & Normal) == 0)
			SetSourceSubscription(true);

		// Update sink subs.
		if((mode & Reverse) == 0) {
			if((_mode & Reverse) != 0)
				SetSinkSubscription(false);
		}
		else if((_mode & Normal) == 0)
			SetSinkSubscription(true);

		_mode = mode;
	}

	void Binding::OnSourceChanged(Property* p) {
		//_sink->CopyFrom(p);
	}

	void Binding::OnSinkChanged(Property* p) {
		//_source->CopyFrom(p);
	}
}