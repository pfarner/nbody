#pragma once

#include "datastructures.h"

namespace Orbit_integration
{
	class Integrator
	{
	public:
		virtual void compute_gravity_step() = 0 {};
		virtual void record_state() = 0 {};
	};

	class Euler : virtual public Integrator
	{
	public:
		Euler::Euler(std::vector<body> &bodies, double time_step = 1) :
			m_bodies(bodies),
			m_time_step(time_step) ,
			m_record_init(false)
		{};

		void compute_gravity_step();
		void record_state();

	private:
		point calculate_single_body_acceleration(int);
		void compute_velocity();
		void update_location();

	protected:
		std::vector<body>& m_bodies;
		double m_time_step;
		bool m_record_init;
	};

	class RK4 : virtual public Integrator
	{
	public:
		RK4::RK4(std::vector<body> &bodies, double time_step = 1) :
			m_bodies(bodies),
			m_time_step(time_step),
			m_record_init(false)
		{};

		void compute_gravity_step();
		void record_state();
		

	private:
		point calculate_single_body_acceleration(int);
		point partial_step(point &, point &, double);
		void compute_velocity();
		void update_location();

	protected:
		std::vector<body>& m_bodies;
		double m_time_step;
		bool m_record_init;
	};
}