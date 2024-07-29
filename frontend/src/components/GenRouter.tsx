import React from 'react';

function GenRouter({ href })
{
    const handleDownload = () => {
        window.location.href = href;
    };

    return (
        <div>
            <button onClick={handleDownload}>Get: {href}.html</button>
        </div>
    );
}

export default GenRouter;
