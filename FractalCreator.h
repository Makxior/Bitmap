#pragma once

#include <string>
#include <cstdint>
#include <memory>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

	class FractalCreator
	{
	private:
		int m_width;
		int m_height;
		unique_ptr<int[]>m_histogram;// we dont allocate MAX_ITERATIONS +1 bcs we want to get rid of that dont go to infinity
		unique_ptr<int[]>m_fractal;// storing that number of iterations for every pixel
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{ 0 };

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	public:
		FractalCreator(int width,int height);
		~FractalCreator();
		void run(string name);
		void addZoom(const Zoom& zoom);
		void addRange(double rangeEnd, const RGB& rgb);

	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(string name);
		int getRange(int iterations) const;
	};