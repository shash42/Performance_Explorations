
Compilation: g++ main.cpp
No flags, optimizations.

**Results**
<details>
<summary> Click </summary>

<pre>
N = 1e6 K = 2
Time taken  : 0.036716 seconds
Done Normally
Time taken  : 0.031017 seconds
Done Interleaved

N = 1e6 K = 10
Time taken  : 0.381972 seconds
Done Normally
Time taken  : 0.178013 seconds
Done Interleaved

N = 1e6 K = 100
Time taken  : 10.2099 seconds
Done Normally
Time taken  : 0.539321 seconds
Done Interleaved

N = 1e5 K = 2
Time taken  : 0.001333 seconds
Done Interleaved
Time taken  : 0.000939 seconds
Done Normally

N = 1e5 K = 10
Time taken  : 0.007708 seconds
Done Interleaved
Time taken  : 0.013965 seconds
Done Normally

N = 1e5 K = 100
Time taken  : 0.060948 seconds
Done Interleaved
Time taken  : 0.365034 seconds
Done Normally

N = 1e5 K = 1000
Time taken  : 0.992374 seconds
Done Interleaved
Time taken  : 3.91468 seconds
Done Normally
</pre>
</details>

**Analysis**
<details>
  <summary> Click </summary>
  <p>
  Assuming the Fetch-Decode-Execute-Memory-Writeback model, most modern architectures can take multiple commands in the pipeline, keeping them in different stages. 
  If an instruction depends on a value computed in the immediate previous instruction, it is highly likely the processor will sit idle for sometime.
  This is because the processor has to wait for the 'Memory' stage of the last instruction to get over before the 'Decode' stage of the current instruction is used.
  In the solve function, each computation is dependent on the previous instruction.
  In the solvealt function, essentially the K different arrays have their operations interleaved, which makes sure there is no immediate data dependencies.
  This is the justification for solvealt being significantly faster.
</details>
