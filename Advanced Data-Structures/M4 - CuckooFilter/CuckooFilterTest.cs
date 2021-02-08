using NUnit.Framework;

namespace M4CuckooFilter
{
    [TestFixture]
    public class CuckooFilterTest
    {
        [Test]
        public void Insert_ValidInput_Success()
        {
            int positives = 1000;
            // Arrange
            var filter = new CuckooFilter(2 * positives, 0.01);

            // Act
            for (int i = 0; i < positives; i++)
                filter.Insert(i);

            // Assert
            for (int i = 0; i < positives; i++)
                Assert.That(filter.Contains(i), Is.True, $"{i} is not tested positive");
            for (int i = positives; i < 2 * positives; i++)
                Assert.That(filter.Contains(i), Is.False, $"{i} is a false positive");
        }

        [Test]
        public void Remove_ValidInput_Success()
        {
            // Arrange
            int numElements = 10000;
            var filter = new CuckooFilter(numElements, 0.01);

            // Act
            for (int i = 0; i < numElements; i++)
                filter.Insert(i);
            for (int i = 0; i < numElements; i++)
                filter.Remove(i);

            // Assert
            for (int i = 0; i < numElements; i++)
                Assert.That(filter.Contains(i), Is.False, $"{i} is not removed");
        }

        //[Test]
        //public void Insert_InvalidInput_Failure()
        //{
        //    // Arrange
        //    var filter = new CuckooFilter<int>(10, 0.01);

        //    // Act
        //    for (int i = 0; i < 100; i++)
        //        filter.Insert(i);

        //    // Assert
        //    Assert.Throws<Exception>(() => filter.Insert(100));
        //}

    }
}
