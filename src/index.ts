import uzumejs from "../pkg/uzumejs"

uzumejs().then(uzume => {
    const contour = new uzume.Contour(1000.0, 2.0);
    console.log(contour.msLength());
})
