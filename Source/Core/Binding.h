#pragma once

namespace Ir
{
	class Property;

	class Binding {
	public:
		enum
		{
			Normal	= 1<<0,
			Reverse = 1<<1,
			TwoWay	= Normal|Reverse
		};
		Binding(Property* source, Property* sink, int mode);

		~Binding();

	public:
		Property const* getSource() const { return _source; }
		Property* getSource() { return _source; }

		Property const* getSink() const { return _sink; }
		Property* getSink() { return _sink; }

		int getMode() const { return _mode; }
		void setMode(int mode);

	protected:
		void OnSourceChanged(Property*);
		void OnSinkChanged(Property*);

	private:
		void SetSourceSubscription(bool sync);
		void SetSinkSubscription(bool sync);

		Property *_source, *_sink;
		int _mode;
	};

	class TemplateBinding : public Binding {
	public:
	protected:
	private:
	};
}