import './App.css'
import WasmPuller from "./components/WasmPuller.tsx";
import GenRouter from "./components/GenRouter.tsx";

function App() {

  return (
    <>
      <div>
          <WasmPuller />
          <GenRouter href="generate-1"/>
          <GenRouter href="generate-2"/>
      </div>
    </>
  )
}

export default App
