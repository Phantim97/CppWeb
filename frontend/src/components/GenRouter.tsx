import React from 'react';

function GenRouter()
{
    const handleDownload = () =>
    {
        window.location.href = '/generate';
    };

    return (
        <div>
            <button onClick={handleDownload}>Get Generated HTML File</button>
        </div>
    );
}

export default GenRouter;
