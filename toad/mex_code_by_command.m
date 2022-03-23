theta = coder.typeof([1.7,35,0.6], [1,3], [0,0]);
ntoads = coder.typeof(66, [1,1], [0,0]);
ndays = coder.typeof(63, [1,1], [0,0]);
model = coder.typeof(1, [1,1], [0,0]);
d0 = coder.typeof(NaN, [1,1], [0,0]);

codegen simulate_toads -args {theta, ntoads, ndays, model, d0}