#pragma once

#include <string>
using namespace std;

namespace ariel
{
	class Point
	{
		private:
			double x_position;
			double y_position;

		public:
			// Constructors:
			Point();
			Point(double x_value, double y_value);

            // Get and Set functions:
			double getX() const;
			double getY() const;
            void setX(double x_position);
			void setY(double y_position);

			/*
			 * Returns distance between this and the other point.
			 */
			double distance(Point other) const;

			/*
			 * Prints the point in the following format "(x,y)".
			 */
			string print() const;

			/*
			 * Returns the closest point from point 'curr' to point 'other' within distance 'max_distance'.
			 */
			static const Point moveTowards(const Point& current, const Point& other, const double max_distance);
	};
}