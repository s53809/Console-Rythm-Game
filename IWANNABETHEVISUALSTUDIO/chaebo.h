#pragma once
#define MAX_CHAEBO_SIZE 246
//(노트 종류), (나오는 타이밍(ms))
int chaebo[MAX_CHAEBO_SIZE][2]{
	{1,100},
	{2,100},
	{3,200},
	{4,300}, // 동치 따락	

	{3,700},
	{2,800},
	{3,900},
	{2,1000},
	{3,1100},
	{2,1200},
	{3,1300},
	{2,1400},
	{3,1500},
	{2,1600}, // 트릴

	{1,1900},
	{2,1900},
	{3,1900},
	{4,1900},

	{1,2100},
	{2,2100},
	{3,2100},
	{4,2100},

	{1,2300},
	{2,2300},
	{3,2300},
	{4,2300},

	{1,2500},
	{2,2500},
	{3,2500},
	{4,2500},

	{1,2700},
	{2,2700},
	{3,2700},
	{4,2700},

	{1,2900},
	{2,2900},
	{3,2900},
	{4,2900},

	{1,3100},
	{2,3100},
	{3,3100},
	{4,3100},

	{1,3300},
	{2,3300},
	{3,3300},
	{4,3300},

	{1,3500},
	{2,3500},
	{3,3500},
	{4,3500},

	{1,3700},
	{2,3700},
	{3,3700},
	{4,3700}, // 4동치 10번

	{1,3900},
	{2,4000},
	{3,4100},
	{4,4200},

	{1,4300},
	{2,4400},
	{3,4500},
	{4,4600},

	{1,4800},
	{2,4900},
	{3,5000},
	{4,5100},

	{1,5200},
	{2,5300},
	{3,5400},
	{4,5500}, // 대계단

	{1,5700},
	{1,5800},

	{3,5900},
	{3,6000},

	{2,6100},
	{2,6200},

	{4,6300},
	{4,6400}, // 따닥따닥

	{1,6600},
	{4,6600},
	{ 3,6700 },
	{ 2,6800 },
	{ 3,6900 },

	{ 1,7000 },
	{ 4,7000 },
	{ 2,7100 },
	{ 3,7200 },
	{ 2,7300 },

	{ 1,7400 },
	{ 4,7400 },
	{ 3,7500 },
	{ 2,7600 },
	{ 3,7700 },

	{ 1, 7800 },
	{ 4,7800 },
	{ 2,7900 },
	{ 3,8000 },
	{ 2,8100 }, // 부등호년

	{ 3,8300 },
	{ 4,8300 },
	{ 3,8400 },
	{ 4,8400 },
	{ 3,8500 },
	{ 3,8500 },

	{ 2,8600 },
	{ 3,8600 },
	{ 2,8700 },
	{ 3,8700 },
	{ 2,8800 },
	{ 3,8800 },

	{ 2,8900 },
	{ 4,8900 },
	{ 2,9000 },
	{ 4,9000 },
	{ 2,9100 },
	{ 4,9100 },

	{ 1,9200 },
	{ 3,9200 },
	{ 1,9300 },
	{ 3,9300 },
	{ 1,9400 },
	{ 3,9400 },

	{ 2,9500 },
	{ 3,9500 },
	{ 2,9600 },
	{ 3,9600 },
	{ 2,9700 },
	{ 3,9700 },

	{ 1,9800 },
	{ 2,9800 },
	{ 1,9900 },
	{ 2,9900 },
	{ 1,10000 },
	{ 2,10000 },//나메 SC 패턴

	{ 1,10200 },
	{ 2,10400 },
	{ 3, 10600 },
	{ 4,10800 },

	{ 1,11000 },
	{ 2,11000 },
	{ 4,11200 },
	{ 2,11400 },
	{ 3,11600 },

	{ 3,11800 },
	{ 4,11800 },
	{ 2,12000 },
	{ 3,12200 },
	{ 2,12400 },

	{ 1,12600 },
	{ 3,12600 },
	{ 2,12800 },
	{ 4,13000 },
	{ 3,13200 }, // 2 1 1 1 패턴

	{ 1,13400 },
	{ 2,13500 },
	{ 3,13600 },
	{ 4,13700 },
	{ 3,13800 },
	{ 2,13900 },
	{ 1,14000 },

	{ 2,14100 },
	{ 3,14200 },
	{ 4,14300 },
	{ 3,14400 },
	{ 2,14500 },
	{ 1,14600 },

	{ 2,14700 },
	{ 3,14800 },
	{ 4,14900 },
	{ 3,15000 },
	{ 2,15100 },
	{ 1,15200 },

	{ 2,15300 },
	{ 3,15400 },
	{ 4,15500 },
	{ 3,15600 },
	{ 2,15700 },
	{ 1,15800 },

	{ 1,16300 },
	{ 4,16300 },
	{ 2,16400 },
	{ 3,16500 },
	{ 4,16600 },

	{ 1,16700 },
	{ 2,16800 },
	{ 4,16900 },
	{ 3,17000 },
	{ 2,17100 },
	{ 1,17200 },

	{ 1,17300 },
	{ 2,17400 },
	{ 3,17600 },

	{ 4,17700 },
	{ 3,17800 },
	{ 2,17900 },
	{ 1,18000 },

	{ 4,18100 },
	{ 3,18200 },

	{ 1,18300 },
	{ 2,18400 },
	{ 3,18500 },
	{ 4,18600 },

	{ 1,18700 },
	{ 2,18800 },
	{ 4,18900 }, //Electric "Sister" Bitch 패턴중 일부

	{ 1,19100 },
	{ 2,19100 },
	{ 2,19250 },
	{ 3,19250 },
	{ 3,19400 },
	{ 4,19400 }, // 2중계단

	{ 1,19600 },
	{ 3,19600 },
	{ 2,19700 },
	{ 4,19700 },
	{ 1,19800 },
	{ 3,19800 },
	{ 2,19900 },
	{ 4,19900 },

	{ 1,20300 },
	{ 4,20300 },
	{ 2,20400 },
	{ 3,20400 },
	{ 1,20500 },
	{ 4,20500 },
	{ 2,20600 },
	{ 3,20600 },

	{ 3,20800 },
	{ 3,21000 },
	{ 3,21200 },

	{ 2,21400 },
	{ 4,21400 },
	{ 1,21500 },
	{ 3,21500 },
	{ 2,21600 },
	{ 4,21600 },
	{ 1,21700 },
	{ 3,21700 },

	{ 2,22100 },
	{ 3,22100 },
	{ 1,22200 },
	{ 4,22200 },
	{ 2,22300 },
	{ 3,22300 },
	{ 1,22400 },
	{ 4,22400 }, //over the top 도입부분
};