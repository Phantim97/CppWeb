import {useState, useEffect} from "react";
import createModule from "../wasm_components/sample.mjs";

function WasmPuller()
{
    const [wasmModule, setWasmModule] = useState(null);
    const [wasmOut, setWasmOut] = useState("");
    const [rngNum, setRngNum] = useState(0);

    useEffect(() => {
        (async () =>
        {
            const res = await createModule();
            setWasmModule(res);
        })();
    }, []);

    //Class testing
    function use_wasm_code()
    {
        const instance = new wasmModule.TestBed("Tim");
        const output = instance.test_out();
        setWasmOut(output);
        instance.delete();
    }

    //Standalone Function
    function external_function()
    {
        const res = wasmModule.rng();
        setRngNum(res);
    }

    return <div>
        <h1>Test</h1>
        <h2>{wasmOut}</h2>
        <h2>My random Number: {rngNum}</h2>
        <button onClick={use_wasm_code}>Pull from Wasm</button>
        <button onClick={external_function}>Give me a random number</button>
    </div>
}

export default WasmPuller;